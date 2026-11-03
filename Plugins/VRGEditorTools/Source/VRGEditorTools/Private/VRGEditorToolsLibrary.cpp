#include "VRGEditorToolsLibrary.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "EdGraphSchema_K2.h"
#include "EdGraphUtilities.h"
#include "Editor.h"
#include "Engine/Blueprint.h"
#include "Engine/SCS_Node.h"
#include "Engine/SimpleConstructionScript.h"
#include "K2Node.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "Kismet2/Kismet2NameValidators.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Misc/UObjectToken.h"
#include "ScopedTransaction.h"
#include "Subsystems/AssetEditorSubsystem.h"

#define LOCTEXT_NAMESPACE "VRGEditorTools"

namespace VRGTools
{
	static FString Err(const FString& Msg) { return TEXT("ERROR: ") + Msg; }

	static FString OneLine(FString S)
	{
		S.ReplaceInline(TEXT("\r"), TEXT(""));
		S.ReplaceInline(TEXT("\n"), TEXT(" | "));
		return S;
	}

	static UBlueprint* LoadBP(const FString& In, FString& OutErr)
	{
		FString Path = In.TrimStartAndEnd();
		if (!Path.StartsWith(TEXT("/")))
		{
			// Short asset name: search the asset registry, preferring /Game/VRG.
			IAssetRegistry& AR = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
			FARFilter Filter;
			Filter.PackagePaths.Add(TEXT("/Game"));
			Filter.bRecursivePaths = true;
			Filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
			Filter.bRecursiveClasses = true;
			TArray<FAssetData> Assets;
			AR.GetAssets(Filter, Assets);
			TArray<FAssetData> Matches;
			for (const FAssetData& A : Assets)
			{
				if (A.AssetName.ToString().Equals(Path, ESearchCase::IgnoreCase))
				{
					Matches.Add(A);
				}
			}
			const FAssetData* Pick = nullptr;
			for (const FAssetData& A : Matches)
			{
				if (A.PackagePath.ToString().StartsWith(TEXT("/Game/VRG")))
				{
					Pick = &A;
					break;
				}
			}
			if (!Pick && Matches.Num() == 1)
			{
				Pick = &Matches[0];
			}
			if (!Pick)
			{
				OutErr = Matches.Num() == 0 ? FString::Printf(TEXT("no Blueprint named '%s'"), *Path)
				                            : FString::Printf(TEXT("'%s' is ambiguous, give the full path"), *Path);
				return nullptr;
			}
			Path = Pick->ObjectPath.ToString();
		}
		else if (!Path.Contains(TEXT(".")))
		{
			Path += TEXT(".") + FPackageName::GetShortName(Path);
		}
		UBlueprint* BP = LoadObject<UBlueprint>(nullptr, *Path);
		if (!BP)
		{
			OutErr = FString::Printf(TEXT("could not load Blueprint '%s'"), *Path);
		}
		return BP;
	}

	static UEdGraph* FindGraph(UBlueprint* BP, const FString& Name, FString& OutErr)
	{
		TArray<UEdGraph*> Graphs;
		BP->GetAllGraphs(Graphs);
		for (UEdGraph* G : Graphs)
		{
			if (G && G->GetName().Equals(Name, ESearchCase::IgnoreCase))
			{
				return G;
			}
		}
		OutErr = FString::Printf(TEXT("no graph '%s' in %s"), *Name, *BP->GetName());
		return nullptr;
	}

	static UEdGraphNode* FindNode(UEdGraph* G, const FString& Name, FString& OutErr)
	{
		for (UEdGraphNode* N : G->Nodes)
		{
			if (N && N->GetName().Equals(Name, ESearchCase::IgnoreCase))
			{
				return N;
			}
		}
		OutErr = FString::Printf(TEXT("no node '%s' in graph %s"), *Name, *G->GetName());
		return nullptr;
	}

	static UEdGraphPin* FindPin(UEdGraphNode* N, const FString& Name, FString& OutErr)
	{
		for (UEdGraphPin* P : N->Pins)
		{
			if (P->PinName.ToString().Equals(Name, ESearchCase::CaseSensitive))
			{
				return P;
			}
		}
		for (UEdGraphPin* P : N->Pins)
		{
			if (P->PinName.ToString().Equals(Name, ESearchCase::IgnoreCase) || P->GetDisplayName().ToString().Equals(Name, ESearchCase::IgnoreCase))
			{
				return P;
			}
		}
		FString Names;
		for (UEdGraphPin* P : N->Pins)
		{
			Names += (Names.IsEmpty() ? TEXT("") : TEXT(", ")) + P->PinName.ToString();
		}
		OutErr = FString::Printf(TEXT("no pin '%s' on %s (pins: %s)"), *Name, *N->GetName(), *Names);
		return nullptr;
	}

	static FString TypeStr(const FEdGraphPinType& T)
	{
		if (T.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			return TEXT("exec");
		}
		return UEdGraphSchema_K2::TypeToText(T).ToString();
	}

	static void DescribeNode(UEdGraphNode* N, FString& Out)
	{
		Out += FString::Printf(TEXT("%s \"%s\" @(%d,%d)"), *N->GetName(), *OneLine(N->GetNodeTitle(ENodeTitleType::FullTitle).ToString()), N->NodePosX, N->NodePosY);
		if (!N->IsNodeEnabled())
		{
			Out += TEXT(" [disabled]");
		}
		if (!N->NodeComment.IsEmpty())
		{
			Out += TEXT(" // ") + OneLine(N->NodeComment);
		}
		Out += TEXT("\n");
		for (UEdGraphPin* P : N->Pins)
		{
			if (P->bHidden && P->LinkedTo.Num() == 0)
			{
				continue;
			}
			const bool bIn = P->Direction == EGPD_Input;
			Out += bIn ? TEXT("  > ") : TEXT("  < ");
			Out += P->PinName.ToString();
			const FString Display = P->GetDisplayName().ToString();
			if (!Display.IsEmpty() && Display != P->PinName.ToString())
			{
				Out += FString::Printf(TEXT(" \"%s\""), *Display);
			}
			Out += FString::Printf(TEXT(" (%s)"), *TypeStr(P->PinType));
			if (bIn && P->LinkedTo.Num() == 0)
			{
				const FString Def = P->GetDefaultAsString();
				if (!Def.IsEmpty())
				{
					Out += TEXT(" = ") + OneLine(Def);
				}
			}
			for (UEdGraphPin* L : P->LinkedTo)
			{
				Out += FString::Printf(TEXT(" %s %s.%s"), bIn ? TEXT("<-") : TEXT("->"), *L->GetOwningNode()->GetName(), *L->PinName.ToString());
			}
			Out += TEXT("\n");
		}
	}

	static FString GraphKind(UBlueprint* BP, UEdGraph* G)
	{
		if (BP->UbergraphPages.Contains(G)) return TEXT("event");
		if (BP->FunctionGraphs.Contains(G)) return TEXT("function");
		if (BP->MacroGraphs.Contains(G)) return TEXT("macro");
		if (BP->DelegateSignatureGraphs.Contains(G)) return TEXT("delegate");
		for (const FBPInterfaceDescription& I : BP->ImplementedInterfaces)
		{
			if (I.Graphs.Contains(G)) return TEXT("interface");
		}
		return TEXT("subgraph");
	}

	template <typename T>
	static T* FindByNameOrPath(const FString& In)
	{
		if (In.StartsWith(TEXT("/")))
		{
			UObject* Obj = LoadObject<UObject>(nullptr, *In);
			if (!Obj && !In.Contains(TEXT(".")))
			{
				Obj = LoadObject<UObject>(nullptr, *(In + TEXT(".") + FPackageName::GetShortName(In)));
			}
			if (UBlueprint* BP = Cast<UBlueprint>(Obj))
			{
				Obj = BP->GeneratedClass;
			}
			return Cast<T>(Obj);
		}
		if (T* Found = FindObject<T>(ANY_PACKAGE, *In))
		{
			return Found;
		}
		// Allow C++ prefixes: AActor, UObject, FVector, EFoo.
		if (In.Len() > 1 && FChar::IsUpper(In[1]) && (In[0] == 'A' || In[0] == 'U' || In[0] == 'F' || In[0] == 'E'))
		{
			return FindObject<T>(ANY_PACKAGE, *In.Mid(1));
		}
		return nullptr;
	}

	static bool ParseType(FString S, FEdGraphPinType& Out, FString& OutErr)
	{
		S.TrimStartAndEndInline();
		Out = FEdGraphPinType();
		if (S.StartsWith(TEXT("&")))
		{
			if (!ParseType(S.Mid(1), Out, OutErr)) return false;
			Out.bIsReference = true;
			return true;
		}
		const FString Lower = S.ToLower();
		auto Inner = [&S](int32 PrefixLen) { return S.Mid(PrefixLen, S.Len() - PrefixLen - 1); };
		if (Lower.StartsWith(TEXT("array<")) && Lower.EndsWith(TEXT(">")))
		{
			if (!ParseType(Inner(6), Out, OutErr)) return false;
			Out.ContainerType = EPinContainerType::Array;
			return true;
		}
		if (Lower.StartsWith(TEXT("set<")) && Lower.EndsWith(TEXT(">")))
		{
			if (!ParseType(Inner(4), Out, OutErr)) return false;
			Out.ContainerType = EPinContainerType::Set;
			return true;
		}
		if (Lower.StartsWith(TEXT("map<")) && Lower.EndsWith(TEXT(">")))
		{
			const FString Body = Inner(4);
			int32 Depth = 0, Split = INDEX_NONE;
			for (int32 i = 0; i < Body.Len(); ++i)
			{
				if (Body[i] == '<') ++Depth;
				else if (Body[i] == '>') --Depth;
				else if (Body[i] == ',' && Depth == 0) { Split = i; break; }
			}
			if (Split == INDEX_NONE) { OutErr = TEXT("map needs map<K,V>"); return false; }
			FEdGraphPinType ValueType;
			if (!ParseType(Body.Left(Split), Out, OutErr) || !ParseType(Body.Mid(Split + 1), ValueType, OutErr)) return false;
			Out.ContainerType = EPinContainerType::Map;
			Out.PinValueType = FEdGraphTerminalType::FromPinType(ValueType);
			return true;
		}

		struct FSimple { const TCHAR* Name; FName Category; UScriptStruct* Struct; };
		const FSimple Simple[] = {
			{TEXT("bool"), UEdGraphSchema_K2::PC_Boolean, nullptr},
			{TEXT("boolean"), UEdGraphSchema_K2::PC_Boolean, nullptr},
			{TEXT("byte"), UEdGraphSchema_K2::PC_Byte, nullptr},
			{TEXT("int"), UEdGraphSchema_K2::PC_Int, nullptr},
			{TEXT("integer"), UEdGraphSchema_K2::PC_Int, nullptr},
			{TEXT("int64"), UEdGraphSchema_K2::PC_Int64, nullptr},
			{TEXT("float"), UEdGraphSchema_K2::PC_Float, nullptr},
			{TEXT("name"), UEdGraphSchema_K2::PC_Name, nullptr},
			{TEXT("string"), UEdGraphSchema_K2::PC_String, nullptr},
			{TEXT("text"), UEdGraphSchema_K2::PC_Text, nullptr},
			{TEXT("vector"), UEdGraphSchema_K2::PC_Struct, TBaseStructure<FVector>::Get()},
			{TEXT("rotator"), UEdGraphSchema_K2::PC_Struct, TBaseStructure<FRotator>::Get()},
			{TEXT("transform"), UEdGraphSchema_K2::PC_Struct, TBaseStructure<FTransform>::Get()},
			{TEXT("vector2d"), UEdGraphSchema_K2::PC_Struct, TBaseStructure<FVector2D>::Get()},
			{TEXT("linearcolor"), UEdGraphSchema_K2::PC_Struct, TBaseStructure<FLinearColor>::Get()},
		};
		for (const FSimple& E : Simple)
		{
			if (Lower == E.Name)
			{
				Out.PinCategory = E.Category;
				Out.PinSubCategoryObject = E.Struct;
				return true;
			}
		}

		FString Kind, Ref = S;
		if (S.Split(TEXT(":"), &Kind, &Ref))
		{
			Kind = Kind.ToLower();
		}
		if (Kind.IsEmpty() || Kind == TEXT("object") || Kind == TEXT("class") || Kind == TEXT("softobject") || Kind == TEXT("softclass") || Kind == TEXT("interface"))
		{
			if (UClass* C = FindByNameOrPath<UClass>(Ref))
			{
				Out.PinCategory = Kind == TEXT("class") ? UEdGraphSchema_K2::PC_Class
					: Kind == TEXT("softobject") ? UEdGraphSchema_K2::PC_SoftObject
					: Kind == TEXT("softclass") ? UEdGraphSchema_K2::PC_SoftClass
					: Kind == TEXT("interface") ? UEdGraphSchema_K2::PC_Interface
					: UEdGraphSchema_K2::PC_Object;
				Out.PinSubCategoryObject = C;
				return true;
			}
		}
		if (Kind.IsEmpty() || Kind == TEXT("struct"))
		{
			if (UScriptStruct* St = FindByNameOrPath<UScriptStruct>(Ref))
			{
				Out.PinCategory = UEdGraphSchema_K2::PC_Struct;
				Out.PinSubCategoryObject = St;
				return true;
			}
		}
		if (Kind.IsEmpty() || Kind == TEXT("enum"))
		{
			if (UEnum* En = FindByNameOrPath<UEnum>(Ref))
			{
				Out.PinCategory = UEdGraphSchema_K2::PC_Byte;
				Out.PinSubCategoryObject = En;
				return true;
			}
		}
		OutErr = FString::Printf(TEXT("unknown type '%s'"), *S);
		return false;
	}

	struct FCtx
	{
		UBlueprint* BP = nullptr;
		UEdGraph* Graph = nullptr;
		FString Error;
	};

	static bool Resolve(FCtx& C, const FString& Blueprint, const FString& Graph, bool bEdit = false)
	{
		// A commandlet saves every modified package when it exits, without asking.
		if (bEdit && IsRunningCommandlet())
		{
			C.Error = TEXT("edits are refused in a commandlet (it would save them on exit); use the open editor");
			return false;
		}
		C.BP = LoadBP(Blueprint, C.Error);
		if (!C.BP) return false;
		if (!Graph.IsEmpty())
		{
			C.Graph = FindGraph(C.BP, Graph, C.Error);
			if (!C.Graph) return false;
		}
		return true;
	}

	static bool CollectNodes(UEdGraph* G, const TArray<FString>& Names, TArray<UEdGraphNode*>& Out, FString& OutErr)
	{
		if (Names.Num() == 0)
		{
			for (UEdGraphNode* N : G->Nodes)
			{
				if (N) Out.Add(N);
			}
			return true;
		}
		for (const FString& Name : Names)
		{
			UEdGraphNode* N = FindNode(G, Name, OutErr);
			if (!N) return false;
			Out.Add(N);
		}
		return true;
	}

	static void SortByPosition(TArray<UEdGraphNode*>& Nodes)
	{
		Nodes.Sort([](const UEdGraphNode& A, const UEdGraphNode& B)
		{
			return A.NodePosX != B.NodePosX ? A.NodePosX < B.NodePosX : A.NodePosY < B.NodePosY;
		});
	}
}

using namespace VRGTools;

FString UVRGEditorToolsLibrary::DescribeBlueprint(const FString& Blueprint)
{
	FCtx C;
	if (!Resolve(C, Blueprint, FString())) return Err(C.Error);
	UBlueprint* BP = C.BP;

	FString Out = FString::Printf(TEXT("Blueprint %s\nParent %s\n"), *BP->GetPathName(), BP->ParentClass ? *BP->ParentClass->GetPathName() : TEXT("?"));

	if (BP->SimpleConstructionScript)
	{
		Out += TEXT("\nComponents:\n");
		for (USCS_Node* N : BP->SimpleConstructionScript->GetAllNodes())
		{
			Out += FString::Printf(TEXT("  %s (%s)\n"), *N->GetVariableName().ToString(), N->ComponentClass ? *N->ComponentClass->GetName() : TEXT("?"));
		}
	}

	Out += TEXT("\nVariables:\n");
	for (const FBPVariableDescription& V : BP->NewVariables)
	{
		Out += FString::Printf(TEXT("  %s (%s)"), *V.VarName.ToString(), *TypeStr(V.VarType));
		if (!V.Category.IsEmpty()) Out += TEXT(" [") + V.Category.ToString() + TEXT("]");
		if (!V.DefaultValue.IsEmpty()) Out += TEXT(" = ") + OneLine(V.DefaultValue);
		Out += TEXT("\n");
	}

	Out += TEXT("\nGraphs:\n");
	TArray<UEdGraph*> Graphs;
	BP->GetAllGraphs(Graphs);
	for (UEdGraph* G : Graphs)
	{
		Out += FString::Printf(TEXT("  %s %s (%d nodes)"), *GraphKind(BP, G), *G->GetName(), G->Nodes.Num());
		UK2Node_FunctionEntry* Entry = nullptr;
		UK2Node_FunctionResult* Result = nullptr;
		for (UEdGraphNode* N : G->Nodes)
		{
			if (!Entry) Entry = Cast<UK2Node_FunctionEntry>(N);
			if (!Result) Result = Cast<UK2Node_FunctionResult>(N);
		}
		if (Entry)
		{
			auto PinList = [](UEdGraphNode* N, EEdGraphPinDirection Dir)
			{
				FString S;
				if (!N) return S;
				for (UEdGraphPin* P : N->Pins)
				{
					if (P->Direction == Dir && P->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec && !P->bHidden)
					{
						S += (S.IsEmpty() ? TEXT("") : TEXT(", ")) + P->PinName.ToString() + TEXT(": ") + TypeStr(P->PinType);
					}
				}
				return S;
			};
			Out += FString::Printf(TEXT(" (%s) -> (%s)"), *PinList(Entry, EGPD_Output), *PinList(Result, EGPD_Input));
			if (Entry->GetExtraFlags() & FUNC_BlueprintPure) Out += TEXT(" pure");
			for (const FBPVariableDescription& L : Entry->LocalVariables)
			{
				Out += FString::Printf(TEXT("\n      local %s (%s)"), *L.VarName.ToString(), *TypeStr(L.VarType));
				if (!L.DefaultValue.IsEmpty()) Out += TEXT(" = ") + OneLine(L.DefaultValue);
			}
		}
		Out += TEXT("\n");
	}
	return Out;
}

FString UVRGEditorToolsLibrary::DescribeGraph(const FString& Blueprint, const FString& Graph, const TArray<FString>& Nodes)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph)) return Err(C.Error);
	TArray<UEdGraphNode*> List;
	if (!CollectNodes(C.Graph, Nodes, List, C.Error)) return Err(C.Error);
	SortByPosition(List);
	FString Out = FString::Printf(TEXT("Graph %s.%s (%s, %d nodes)\n"), *C.BP->GetName(), *C.Graph->GetName(), *GraphKind(C.BP, C.Graph), C.Graph->Nodes.Num());
	for (UEdGraphNode* N : List)
	{
		DescribeNode(N, Out);
	}
	return Out;
}

FString UVRGEditorToolsLibrary::ExportNodes(const FString& Blueprint, const FString& Graph, const TArray<FString>& Nodes)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph)) return Err(C.Error);
	TArray<UEdGraphNode*> List;
	if (!CollectNodes(C.Graph, Nodes, List, C.Error)) return Err(C.Error);
	TSet<UObject*> ToExport;
	for (UEdGraphNode* N : List)
	{
		N->PrepareForCopying();
		ToExport.Add(N);
	}
	FString Text;
	FEdGraphUtilities::ExportNodesToText(ToExport, Text);
	return Text;
}

FString UVRGEditorToolsLibrary::ImportNodes(const FString& Blueprint, const FString& Graph, const FString& Text, bool bKeepPositions)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph, true)) return Err(C.Error);
	if (!FEdGraphUtilities::CanImportNodesFromText(C.Graph, Text))
	{
		return Err(TEXT("this text can't be pasted into this graph (wrong format, or node types not allowed here)"));
	}

	const TArray<UEdGraphNode*> Existing = C.Graph->Nodes;

	const FScopedTransaction Transaction(LOCTEXT("ImportNodes", "VRG: paste nodes"));
	C.Graph->Modify();
	TSet<UEdGraphNode*> Pasted;
	FEdGraphUtilities::ImportNodesFromText(C.Graph, Text, Pasted);
	if (Pasted.Num() == 0)
	{
		return Err(TEXT("no nodes were created"));
	}

	if (!bKeepPositions)
	{
		int32 MinX = MAX_int32, MinY = MAX_int32;
		for (UEdGraphNode* N : Pasted)
		{
			MinX = FMath::Min(MinX, N->NodePosX);
			MinY = FMath::Min(MinY, N->NodePosY);
		}
		int32 AnchorX = 0, AnchorY = 0;
		if (Existing.Num() > 0)
		{
			AnchorX = MIN_int32;
			AnchorY = MAX_int32;
			for (UEdGraphNode* N : Existing)
			{
				if (!N) continue;
				AnchorX = FMath::Max(AnchorX, N->NodePosX + FMath::Max(N->NodeWidth, 300));
				AnchorY = FMath::Min(AnchorY, N->NodePosY);
			}
			AnchorX += 200;
		}
		for (UEdGraphNode* N : Pasted)
		{
			N->NodePosX += AnchorX - MinX;
			N->NodePosY += AnchorY - MinY;
		}
	}

	bool bStructural = false;
	for (UEdGraphNode* N : Pasted)
	{
		N->SnapToGrid(16);
		N->CreateNewGuid();
		if (UK2Node* K2 = Cast<UK2Node>(N))
		{
			bStructural |= K2->NodeCausesStructuralBlueprintChange();
		}
	}
	if (bStructural)
	{
		FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(C.BP);
	}
	else
	{
		FBlueprintEditorUtils::MarkBlueprintAsModified(C.BP);
	}

	TArray<UEdGraphNode*> List = Pasted.Array();
	SortByPosition(List);
	FString Out = FString::Printf(TEXT("Pasted %d nodes into %s.%s:\n"), List.Num(), *C.BP->GetName(), *C.Graph->GetName());
	for (UEdGraphNode* N : List)
	{
		DescribeNode(N, Out);
	}
	return Out;
}

FString UVRGEditorToolsLibrary::AddFunction(const FString& Blueprint, const FString& Name, const TArray<FString>& Inputs, const TArray<FString>& Outputs, bool bPure, const FString& Category)
{
	FCtx C;
	if (!Resolve(C, Blueprint, FString(), true)) return Err(C.Error);

	const TSharedPtr<INameValidatorInterface> Validator = MakeShareable(new FKismetNameValidator(C.BP));
	if (Validator->IsValid(Name) != EValidatorResult::Ok)
	{
		return Err(FString::Printf(TEXT("name '%s' is invalid or already used in %s"), *Name, *C.BP->GetName()));
	}

	auto ParseParams = [&C](const TArray<FString>& Specs, TArray<TPair<FName, FEdGraphPinType>>& Out)
	{
		for (const FString& Spec : Specs)
		{
			FString PName, PType;
			if (!Spec.Split(TEXT(":"), &PName, &PType))
			{
				C.Error = FString::Printf(TEXT("parameter '%s' must be Name:type"), *Spec);
				return false;
			}
			FEdGraphPinType T;
			if (!ParseType(PType, T, C.Error)) return false;
			Out.Emplace(FName(*PName.TrimStartAndEnd()), T);
		}
		return true;
	};
	TArray<TPair<FName, FEdGraphPinType>> In, OutParams;
	if (!ParseParams(Inputs, In) || !ParseParams(Outputs, OutParams)) return Err(C.Error);

	const FScopedTransaction Transaction(LOCTEXT("AddFunction", "VRG: add function"));
	C.BP->Modify();
	UEdGraph* G = FBlueprintEditorUtils::CreateNewGraph(C.BP, FName(*Name), UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
	FBlueprintEditorUtils::AddFunctionGraph<UClass>(C.BP, G, /*bIsUserCreated*/ true, nullptr);

	UK2Node_FunctionEntry* Entry = nullptr;
	for (UEdGraphNode* N : G->Nodes)
	{
		if (!Entry) Entry = Cast<UK2Node_FunctionEntry>(N);
	}
	if (!Entry) return Err(TEXT("function created but its entry node is missing"));

	Entry->Modify();
	if (bPure) Entry->AddExtraFlags(FUNC_BlueprintPure);
	if (!Category.IsEmpty()) Entry->MetaData.Category = FText::FromString(Category);
	for (const auto& P : In)
	{
		Entry->CreateUserDefinedPin(P.Key, P.Value, EGPD_Output, false);
	}
	Entry->ReconstructNode();
	if (OutParams.Num() > 0)
	{
		UK2Node_FunctionResult* Result = FBlueprintEditorUtils::FindOrCreateFunctionResultNode(Entry);
		Result->Modify();
		for (const auto& P : OutParams)
		{
			Result->CreateUserDefinedPin(P.Key, P.Value, EGPD_Input, false);
		}
		Result->ReconstructNode();
	}
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(C.BP);
	return DescribeGraph(Blueprint, G->GetName(), TArray<FString>());
}

FString UVRGEditorToolsLibrary::AddMemberVariable(const FString& Blueprint, const FString& Name, const FString& Type, const FString& DefaultValue, const FString& Category)
{
	FCtx C;
	if (!Resolve(C, Blueprint, FString(), true)) return Err(C.Error);
	FEdGraphPinType T;
	if (!ParseType(Type, T, C.Error)) return Err(C.Error);
	const FScopedTransaction Transaction(LOCTEXT("AddMemberVariable", "VRG: add variable"));
	C.BP->Modify();
	if (!FBlueprintEditorUtils::AddMemberVariable(C.BP, FName(*Name), T, DefaultValue))
	{
		return Err(FString::Printf(TEXT("could not add variable '%s' (name already used?)"), *Name));
	}
	if (!Category.IsEmpty())
	{
		FBlueprintEditorUtils::SetBlueprintVariableCategory(C.BP, FName(*Name), nullptr, FText::FromString(Category));
	}
	return FString::Printf(TEXT("Added variable %s (%s) to %s"), *Name, *TypeStr(T), *C.BP->GetName());
}

FString UVRGEditorToolsLibrary::AddLocalVariable(const FString& Blueprint, const FString& Function, const FString& Name, const FString& Type, const FString& DefaultValue)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Function, true)) return Err(C.Error);
	if (GraphKind(C.BP, C.Graph) != TEXT("function")) return Err(TEXT("local variables need a function graph"));
	FEdGraphPinType T;
	if (!ParseType(Type, T, C.Error)) return Err(C.Error);
	const FScopedTransaction Transaction(LOCTEXT("AddLocalVariable", "VRG: add local variable"));
	C.BP->Modify();
	if (!FBlueprintEditorUtils::AddLocalVariable(C.BP, C.Graph, FName(*Name), T, DefaultValue))
	{
		return Err(FString::Printf(TEXT("could not add local '%s' (name already used?)"), *Name));
	}
	return FString::Printf(TEXT("Added local %s (%s) to %s.%s"), *Name, *TypeStr(T), *C.BP->GetName(), *Function);
}

FString UVRGEditorToolsLibrary::Link(const FString& Blueprint, const FString& Graph, const FString& NodeA, const FString& PinA, const FString& NodeB, const FString& PinB)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph, true)) return Err(C.Error);
	UEdGraphNode* NA = FindNode(C.Graph, NodeA, C.Error);
	UEdGraphNode* NB = NA ? FindNode(C.Graph, NodeB, C.Error) : nullptr;
	UEdGraphPin* PA = NB ? FindPin(NA, PinA, C.Error) : nullptr;
	UEdGraphPin* PB = PA ? FindPin(NB, PinB, C.Error) : nullptr;
	if (!PB) return Err(C.Error);

	const UEdGraphSchema* Schema = C.Graph->GetSchema();
	const FPinConnectionResponse Response = Schema->CanCreateConnection(PA, PB);
	if (Response.Response == CONNECT_RESPONSE_DISALLOW)
	{
		return Err(FString::Printf(TEXT("can't link %s.%s and %s.%s: %s"), *NodeA, *PinA, *NodeB, *PinB, *Response.Message.ToString()));
	}
	const FScopedTransaction Transaction(LOCTEXT("Link", "VRG: link pins"));
	C.Graph->Modify();
	if (!Schema->TryCreateConnection(PA, PB))
	{
		return Err(TEXT("link refused by the schema"));
	}
	FBlueprintEditorUtils::MarkBlueprintAsModified(C.BP);
	FString Out = FString::Printf(TEXT("Linked %s.%s and %s.%s"), *NodeA, *PinA, *NodeB, *PinB);
	if (!Response.Message.IsEmpty())
	{
		Out += TEXT(" (") + Response.Message.ToString() + TEXT(")");
	}
	return Out;
}

FString UVRGEditorToolsLibrary::Unlink(const FString& Blueprint, const FString& Graph, const FString& NodeA, const FString& PinA, const FString& NodeB, const FString& PinB)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph, true)) return Err(C.Error);
	UEdGraphNode* NA = FindNode(C.Graph, NodeA, C.Error);
	UEdGraphPin* PA = NA ? FindPin(NA, PinA, C.Error) : nullptr;
	if (!PA) return Err(C.Error);
	const UEdGraphSchema* Schema = C.Graph->GetSchema();
	const FScopedTransaction Transaction(LOCTEXT("Unlink", "VRG: break link"));
	C.Graph->Modify();
	if (NodeB.IsEmpty())
	{
		const int32 Count = PA->LinkedTo.Num();
		Schema->BreakPinLinks(*PA, true);
		FBlueprintEditorUtils::MarkBlueprintAsModified(C.BP);
		return FString::Printf(TEXT("Broke %d link(s) of %s.%s"), Count, *NodeA, *PinA);
	}
	UEdGraphNode* NB = FindNode(C.Graph, NodeB, C.Error);
	UEdGraphPin* PB = NB ? FindPin(NB, PinB, C.Error) : nullptr;
	if (!PB) return Err(C.Error);
	if (!PA->LinkedTo.Contains(PB)) return Err(TEXT("these pins are not linked"));
	Schema->BreakSinglePinLink(PA, PB);
	FBlueprintEditorUtils::MarkBlueprintAsModified(C.BP);
	return FString::Printf(TEXT("Unlinked %s.%s and %s.%s"), *NodeA, *PinA, *NodeB, *PinB);
}

FString UVRGEditorToolsLibrary::SetPinDefault(const FString& Blueprint, const FString& Graph, const FString& Node, const FString& Pin, const FString& Value)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph, true)) return Err(C.Error);
	UEdGraphNode* N = FindNode(C.Graph, Node, C.Error);
	UEdGraphPin* P = N ? FindPin(N, Pin, C.Error) : nullptr;
	if (!P) return Err(C.Error);
	if (P->Direction != EGPD_Input) return Err(TEXT("only input pins have defaults"));

	const UEdGraphSchema_K2* K2 = GetDefault<UEdGraphSchema_K2>();
	const FName Cat = P->PinType.PinCategory;
	const bool bObject = Cat == UEdGraphSchema_K2::PC_Object || Cat == UEdGraphSchema_K2::PC_Class || Cat == UEdGraphSchema_K2::PC_Interface;

	const FScopedTransaction Transaction(LOCTEXT("SetPinDefault", "VRG: set pin default"));
	N->Modify();
	if (bObject)
	{
		UObject* Obj = nullptr;
		if (!Value.IsEmpty())
		{
			Obj = LoadObject<UObject>(nullptr, *Value);
			if (UBlueprint* BPObj = Cast<UBlueprint>(Obj))
			{
				if (Cat == UEdGraphSchema_K2::PC_Class) Obj = BPObj->GeneratedClass;
			}
			if (!Obj) return Err(FString::Printf(TEXT("could not load object '%s'"), *Value));
		}
		K2->TrySetDefaultObject(*P, Obj);
	}
	else if (Cat == UEdGraphSchema_K2::PC_Text)
	{
		K2->TrySetDefaultText(*P, FText::FromString(Value));
	}
	else
	{
		const FString Problem = K2->IsPinDefaultValid(P, Value, nullptr, FText::GetEmpty());
		if (!Problem.IsEmpty()) return Err(Problem);
		K2->TrySetDefaultValue(*P, Value);
	}
	return FString::Printf(TEXT("%s.%s = %s"), *Node, *Pin, *P->GetDefaultAsString());
}

FString UVRGEditorToolsLibrary::RemoveNodes(const FString& Blueprint, const FString& Graph, const TArray<FString>& Nodes)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph, true)) return Err(C.Error);
	if (Nodes.Num() == 0) return Err(TEXT("no nodes given"));
	TArray<UEdGraphNode*> List;
	if (!CollectNodes(C.Graph, Nodes, List, C.Error)) return Err(C.Error);
	for (UEdGraphNode* N : List)
	{
		if (!N->CanUserDeleteNode()) return Err(FString::Printf(TEXT("%s can't be deleted"), *N->GetName()));
	}
	const FScopedTransaction Transaction(LOCTEXT("RemoveNodes", "VRG: delete nodes"));
	C.Graph->Modify();
	for (UEdGraphNode* N : List)
	{
		FBlueprintEditorUtils::RemoveNode(C.BP, N, true);
	}
	return FString::Printf(TEXT("Removed %d node(s)"), List.Num());
}

FString UVRGEditorToolsLibrary::MoveNode(const FString& Blueprint, const FString& Graph, const FString& Node, int32 X, int32 Y)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph, true)) return Err(C.Error);
	UEdGraphNode* N = FindNode(C.Graph, Node, C.Error);
	if (!N) return Err(C.Error);
	const FScopedTransaction Transaction(LOCTEXT("MoveNode", "VRG: move node"));
	N->Modify();
	N->NodePosX = X;
	N->NodePosY = Y;
	return FString::Printf(TEXT("Moved %s to (%d,%d)"), *Node, X, Y);
}

FString UVRGEditorToolsLibrary::Compile(const FString& Blueprint)
{
	FCtx C;
	if (!Resolve(C, Blueprint, FString(), true)) return Err(C.Error);
	FCompilerResultsLog Log;
	Log.SetSourcePath(C.BP->GetPathName());
	FKismetEditorUtilities::CompileBlueprint(C.BP, EBlueprintCompileOptions::None, &Log);

	FString Out = FString::Printf(TEXT("Compiled %s: %d error(s), %d warning(s)\n"), *C.BP->GetName(), Log.NumErrors, Log.NumWarnings);
	for (const TSharedRef<FTokenizedMessage>& Msg : Log.Messages)
	{
		const EMessageSeverity::Type Sev = Msg->GetSeverity();
		const bool bError = Sev == EMessageSeverity::Error || Sev == EMessageSeverity::CriticalError;
		const bool bWarning = Sev == EMessageSeverity::Warning || Sev == EMessageSeverity::PerformanceWarning;
		if (!bError && !bWarning)
		{
			continue; // "Compile of X successful!" and similar notes
		}
		const TCHAR* Label = bError ? TEXT("error") : TEXT("warning");
		FString Line;
		for (const TSharedRef<IMessageToken>& Tok : Msg->GetMessageTokens())
		{
			Line += Tok->ToText().ToString();
			if (Tok->GetType() == EMessageToken::Object)
			{
				const UObject* Obj = StaticCastSharedRef<FUObjectToken>(Tok)->GetObject().Get();
				if (const UEdGraphNode* N = Cast<UEdGraphNode>(Obj))
				{
					Line += FString::Printf(TEXT(" [%s in %s]"), *N->GetName(), N->GetGraph() ? *N->GetGraph()->GetName() : TEXT("?"));
				}
			}
		}
		Out += FString::Printf(TEXT("  %s: %s\n"), Label, *OneLine(Line));
	}
	return Out;
}

FString UVRGEditorToolsLibrary::Focus(const FString& Blueprint, const FString& Graph, const FString& Node)
{
	FCtx C;
	if (!Resolve(C, Blueprint, Graph)) return Err(C.Error);
	UObject* Target = C.Graph ? static_cast<UObject*>(C.Graph) : C.BP;
	if (!Node.IsEmpty() && C.Graph)
	{
		UEdGraphNode* N = FindNode(C.Graph, Node, C.Error);
		if (!N) return Err(C.Error);
		Target = N;
	}
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(C.BP);
	if (Target != C.BP)
	{
		FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Target);
	}
	return FString::Printf(TEXT("Opened %s on %s"), *C.BP->GetName(), *Target->GetName());
}

#undef LOCTEXT_NAMESPACE
