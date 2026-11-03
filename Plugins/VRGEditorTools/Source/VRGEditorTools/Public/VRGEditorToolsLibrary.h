#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VRGEditorToolsLibrary.generated.h"

/**
 * Editor-only helpers to read and edit Blueprint graphs from Python
 * (unreal.VRGEditorToolsLibrary). Driven by Scripts/ue.py over Python remote execution.
 *
 * Conventions:
 * - Blueprint: "/Game/VRG/VRUIManager" or just "VRUIManager" (searched under /Game).
 * - Graph: graph name as shown in My Blueprint ("EventGraph", a function name, a macro name...).
 * - Node: the node's object name, as printed by DescribeGraph (e.g. "K2Node_CallFunction_12").
 * - Types: bool, byte, int, int64, float, name, string, text, vector, rotator, transform,
 *   vector2d, linearcolor, object:<Class>, class:<Class>, softobject:<Class>, softclass:<Class>,
 *   struct:<Struct>, enum:<Enum>, array<T>, set<T>, map<K,V>, or a bare class/struct/enum name.
 *   <Class> is a short native name ("Actor") or a path ("/Game/VRG/BP_MotionController").
 *   Prefix "&" for a by-reference function input.
 * - Every function returns text. Failures start with "ERROR:".
 * - Nothing is ever saved: the user reviews and saves in the editor.
 */
UCLASS()
class UVRGEditorToolsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Parent class, graphs (with kind and node count), member variables, function signatures and locals. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString DescribeBlueprint(const FString& Blueprint);

	/** Compact text listing of nodes, pins, defaults and links. Nodes empty = whole graph. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString DescribeGraph(const FString& Blueprint, const FString& Graph, const TArray<FString>& Nodes);

	/** Same text as Ctrl+C in the editor. Nodes empty = whole graph. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString ExportNodes(const FString& Blueprint, const FString& Graph, const TArray<FString>& Nodes);

	/** Same as Ctrl+V. Unless bKeepPositions, the nodes are placed to the right of the existing ones. Returns DescribeGraph of the new nodes. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString ImportNodes(const FString& Blueprint, const FString& Graph, const FString& Text, bool bKeepPositions);

	/** New function graph. Inputs/Outputs entries are "Name:type". */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString AddFunction(const FString& Blueprint, const FString& Name, const TArray<FString>& Inputs, const TArray<FString>& Outputs, bool bPure, const FString& Category);

	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString AddMemberVariable(const FString& Blueprint, const FString& Name, const FString& Type, const FString& DefaultValue, const FString& Category);

	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString AddLocalVariable(const FString& Blueprint, const FString& Function, const FString& Name, const FString& Type, const FString& DefaultValue);

	/** Connects two pins (either order). Conversion nodes are added when the schema allows it. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString Link(const FString& Blueprint, const FString& Graph, const FString& NodeA, const FString& PinA, const FString& NodeB, const FString& PinB);

	/** Breaks one link, or every link of PinA when NodeB is empty. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString Unlink(const FString& Blueprint, const FString& Graph, const FString& NodeA, const FString& PinA, const FString& NodeB, const FString& PinB);

	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString SetPinDefault(const FString& Blueprint, const FString& Graph, const FString& Node, const FString& Pin, const FString& Value);

	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString RemoveNodes(const FString& Blueprint, const FString& Graph, const TArray<FString>& Nodes);

	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString MoveNode(const FString& Blueprint, const FString& Graph, const FString& Node, int32 X, int32 Y);

	/** Compiles and returns the compiler messages (with node names). */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString Compile(const FString& Blueprint);

	/** Opens the Blueprint editor on a graph, and on a node if given. */
	UFUNCTION(BlueprintCallable, Category = "VRG Editor Tools")
	static FString Focus(const FString& Blueprint, const FString& Graph, const FString& Node);
};
