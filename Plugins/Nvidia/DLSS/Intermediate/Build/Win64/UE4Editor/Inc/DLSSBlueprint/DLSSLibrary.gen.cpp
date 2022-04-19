// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DLSSBlueprint/Public/DLSSLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDLSSLibrary() {}
// Cross Module References
	DLSSBLUEPRINT_API UClass* Z_Construct_UClass_UDLSSLibrary_NoRegister();
	DLSSBLUEPRINT_API UClass* Z_Construct_UClass_UDLSSLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_DLSSBlueprint();
	DLSSBLUEPRINT_API UEnum* Z_Construct_UEnum_DLSSBlueprint_UDLSSMode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	DLSSBLUEPRINT_API UEnum* Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport();
// End Cross Module References
	DEFINE_FUNCTION(UDLSSLibrary::execEnableDLAA)
	{
		P_GET_UBOOL(Z_Param_bEnabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDLSSLibrary::EnableDLAA(Z_Param_bEnabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetDefaultDLSSMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDLSSMode*)Z_Param__Result=UDLSSLibrary::GetDefaultDLSSMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetDLSSMinimumDriverVersion)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_MinDriverVersionMajor);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_MinDriverVersionMinor);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDLSSLibrary::GetDLSSMinimumDriverVersion(Z_Param_Out_MinDriverVersionMajor,Z_Param_Out_MinDriverVersionMinor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetDLSSMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDLSSMode*)Z_Param__Result=UDLSSLibrary::GetDLSSMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetDLSSModeInformation)
	{
		P_GET_ENUM(UDLSSMode,Z_Param_DLSSMode);
		P_GET_STRUCT(FVector2D,Z_Param_ScreenResolution);
		P_GET_UBOOL_REF(Z_Param_Out_bIsSupported);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OptimalScreenPercentage);
		P_GET_UBOOL_REF(Z_Param_Out_bIsFixedScreenPercentage);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MinScreenPercentage);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MaxScreenPercentage);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OptimalSharpness);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDLSSLibrary::GetDLSSModeInformation(UDLSSMode(Z_Param_DLSSMode),Z_Param_ScreenResolution,Z_Param_Out_bIsSupported,Z_Param_Out_OptimalScreenPercentage,Z_Param_Out_bIsFixedScreenPercentage,Z_Param_Out_MinScreenPercentage,Z_Param_Out_MaxScreenPercentage,Z_Param_Out_OptimalSharpness);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetDLSSScreenPercentageRange)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MinScreenPercentage);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_MaxScreenPercentage);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDLSSLibrary::GetDLSSScreenPercentageRange(Z_Param_Out_MinScreenPercentage,Z_Param_Out_MaxScreenPercentage);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetDLSSSharpness)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UDLSSLibrary::GetDLSSSharpness();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execGetSupportedDLSSModes)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UDLSSMode>*)Z_Param__Result=UDLSSLibrary::GetSupportedDLSSModes();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execIsDLAAEnabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDLSSLibrary::IsDLAAEnabled();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execIsDLSSModeSupported)
	{
		P_GET_ENUM(UDLSSMode,Z_Param_DLSSMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDLSSLibrary::IsDLSSModeSupported(UDLSSMode(Z_Param_DLSSMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execIsDLSSSupported)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDLSSLibrary::IsDLSSSupported();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execQueryDLSSSupport)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDLSSSupport*)Z_Param__Result=UDLSSLibrary::QueryDLSSSupport();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execSetDLSSMode)
	{
		P_GET_ENUM(UDLSSMode,Z_Param_DLSSMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDLSSLibrary::SetDLSSMode(UDLSSMode(Z_Param_DLSSMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDLSSLibrary::execSetDLSSSharpness)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Sharpness);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDLSSLibrary::SetDLSSSharpness(Z_Param_Sharpness);
		P_NATIVE_END;
	}
	void UDLSSLibrary::StaticRegisterNativesUDLSSLibrary()
	{
		UClass* Class = UDLSSLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EnableDLAA", &UDLSSLibrary::execEnableDLAA },
			{ "GetDefaultDLSSMode", &UDLSSLibrary::execGetDefaultDLSSMode },
			{ "GetDLSSMinimumDriverVersion", &UDLSSLibrary::execGetDLSSMinimumDriverVersion },
			{ "GetDLSSMode", &UDLSSLibrary::execGetDLSSMode },
			{ "GetDLSSModeInformation", &UDLSSLibrary::execGetDLSSModeInformation },
			{ "GetDLSSScreenPercentageRange", &UDLSSLibrary::execGetDLSSScreenPercentageRange },
			{ "GetDLSSSharpness", &UDLSSLibrary::execGetDLSSSharpness },
			{ "GetSupportedDLSSModes", &UDLSSLibrary::execGetSupportedDLSSModes },
			{ "IsDLAAEnabled", &UDLSSLibrary::execIsDLAAEnabled },
			{ "IsDLSSModeSupported", &UDLSSLibrary::execIsDLSSModeSupported },
			{ "IsDLSSSupported", &UDLSSLibrary::execIsDLSSSupported },
			{ "QueryDLSSSupport", &UDLSSLibrary::execQueryDLSSSupport },
			{ "SetDLSSMode", &UDLSSLibrary::execSetDLSSMode },
			{ "SetDLSSSharpness", &UDLSSLibrary::execSetDLSSSharpness },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics
	{
		struct DLSSLibrary_eventEnableDLAA_Parms
		{
			bool bEnabled;
		};
		static void NewProp_bEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::NewProp_bEnabled_SetBit(void* Obj)
	{
		((DLSSLibrary_eventEnableDLAA_Parms*)Obj)->bEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DLSSLibrary_eventEnableDLAA_Parms), &Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::NewProp_bEnabled,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "EnableDLAA", nullptr, nullptr, sizeof(DLSSLibrary_eventEnableDLAA_Parms), Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_EnableDLAA()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_EnableDLAA_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics
	{
		struct DLSSLibrary_eventGetDefaultDLSSMode_Parms
		{
			UDLSSMode ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDefaultDLSSMode_Parms, ReturnValue), Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::NewProp_ReturnValue_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetDefaultDLSSMode", nullptr, nullptr, sizeof(DLSSLibrary_eventGetDefaultDLSSMode_Parms), Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics
	{
		struct DLSSLibrary_eventGetDLSSMinimumDriverVersion_Parms
		{
			int32 MinDriverVersionMajor;
			int32 MinDriverVersionMinor;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MinDriverVersionMajor;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MinDriverVersionMinor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::NewProp_MinDriverVersionMajor = { "MinDriverVersionMajor", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSMinimumDriverVersion_Parms, MinDriverVersionMajor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::NewProp_MinDriverVersionMinor = { "MinDriverVersionMinor", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSMinimumDriverVersion_Parms, MinDriverVersionMinor), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::NewProp_MinDriverVersionMajor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::NewProp_MinDriverVersionMinor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetDLSSMinimumDriverVersion", nullptr, nullptr, sizeof(DLSSLibrary_eventGetDLSSMinimumDriverVersion_Parms), Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics
	{
		struct DLSSLibrary_eventGetDLSSMode_Parms
		{
			UDLSSMode ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSMode_Parms, ReturnValue), Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::NewProp_ReturnValue_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetDLSSMode", nullptr, nullptr, sizeof(DLSSLibrary_eventGetDLSSMode_Parms), Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics
	{
		struct DLSSLibrary_eventGetDLSSModeInformation_Parms
		{
			UDLSSMode DLSSMode;
			FVector2D ScreenResolution;
			bool bIsSupported;
			float OptimalScreenPercentage;
			bool bIsFixedScreenPercentage;
			float MinScreenPercentage;
			float MaxScreenPercentage;
			float OptimalSharpness;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DLSSMode_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DLSSMode;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ScreenResolution;
		static void NewProp_bIsSupported_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsSupported;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OptimalScreenPercentage;
		static void NewProp_bIsFixedScreenPercentage_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsFixedScreenPercentage;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinScreenPercentage;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxScreenPercentage;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OptimalSharpness;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_DLSSMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_DLSSMode = { "DLSSMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSModeInformation_Parms, DLSSMode), Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_ScreenResolution = { "ScreenResolution", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSModeInformation_Parms, ScreenResolution), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsSupported_SetBit(void* Obj)
	{
		((DLSSLibrary_eventGetDLSSModeInformation_Parms*)Obj)->bIsSupported = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsSupported = { "bIsSupported", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DLSSLibrary_eventGetDLSSModeInformation_Parms), &Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsSupported_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_OptimalScreenPercentage = { "OptimalScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSModeInformation_Parms, OptimalScreenPercentage), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsFixedScreenPercentage_SetBit(void* Obj)
	{
		((DLSSLibrary_eventGetDLSSModeInformation_Parms*)Obj)->bIsFixedScreenPercentage = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsFixedScreenPercentage = { "bIsFixedScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DLSSLibrary_eventGetDLSSModeInformation_Parms), &Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsFixedScreenPercentage_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_MinScreenPercentage = { "MinScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSModeInformation_Parms, MinScreenPercentage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_MaxScreenPercentage = { "MaxScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSModeInformation_Parms, MaxScreenPercentage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_OptimalSharpness = { "OptimalSharpness", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSModeInformation_Parms, OptimalSharpness), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_DLSSMode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_DLSSMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_ScreenResolution,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsSupported,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_OptimalScreenPercentage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_bIsFixedScreenPercentage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_MinScreenPercentage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_MaxScreenPercentage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::NewProp_OptimalSharpness,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetDLSSModeInformation", nullptr, nullptr, sizeof(DLSSLibrary_eventGetDLSSModeInformation_Parms), Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics
	{
		struct DLSSLibrary_eventGetDLSSScreenPercentageRange_Parms
		{
			float MinScreenPercentage;
			float MaxScreenPercentage;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinScreenPercentage;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxScreenPercentage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::NewProp_MinScreenPercentage = { "MinScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSScreenPercentageRange_Parms, MinScreenPercentage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::NewProp_MaxScreenPercentage = { "MaxScreenPercentage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSScreenPercentageRange_Parms, MaxScreenPercentage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::NewProp_MinScreenPercentage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::NewProp_MaxScreenPercentage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetDLSSScreenPercentageRange", nullptr, nullptr, sizeof(DLSSLibrary_eventGetDLSSScreenPercentageRange_Parms), Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics
	{
		struct DLSSLibrary_eventGetDLSSSharpness_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetDLSSSharpness_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetDLSSSharpness", nullptr, nullptr, sizeof(DLSSLibrary_eventGetDLSSSharpness_Parms), Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics
	{
		struct DLSSLibrary_eventGetSupportedDLSSModes_Parms
		{
			TArray<UDLSSMode> ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventGetSupportedDLSSModes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "GetSupportedDLSSModes", nullptr, nullptr, sizeof(DLSSLibrary_eventGetSupportedDLSSModes_Parms), Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics
	{
		struct DLSSLibrary_eventIsDLAAEnabled_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DLSSLibrary_eventIsDLAAEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DLSSLibrary_eventIsDLAAEnabled_Parms), &Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "IsDLAAEnabled", nullptr, nullptr, sizeof(DLSSLibrary_eventIsDLAAEnabled_Parms), Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics
	{
		struct DLSSLibrary_eventIsDLSSModeSupported_Parms
		{
			UDLSSMode DLSSMode;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DLSSMode_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DLSSMode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_DLSSMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_DLSSMode = { "DLSSMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventIsDLSSModeSupported_Parms, DLSSMode), Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DLSSLibrary_eventIsDLSSModeSupported_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DLSSLibrary_eventIsDLSSModeSupported_Parms), &Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_DLSSMode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_DLSSMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "IsDLSSModeSupported", nullptr, nullptr, sizeof(DLSSLibrary_eventIsDLSSModeSupported_Parms), Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics
	{
		struct DLSSLibrary_eventIsDLSSSupported_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DLSSLibrary_eventIsDLSSSupported_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DLSSLibrary_eventIsDLSSSupported_Parms), &Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "IsDLSSSupported", nullptr, nullptr, sizeof(DLSSLibrary_eventIsDLSSSupported_Parms), Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics
	{
		struct DLSSLibrary_eventQueryDLSSSupport_Parms
		{
			UDLSSSupport ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventQueryDLSSSupport_Parms, ReturnValue), Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::NewProp_ReturnValue_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "QueryDLSSSupport", nullptr, nullptr, sizeof(DLSSLibrary_eventQueryDLSSSupport_Parms), Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics
	{
		struct DLSSLibrary_eventSetDLSSMode_Parms
		{
			UDLSSMode DLSSMode;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DLSSMode_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DLSSMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::NewProp_DLSSMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::NewProp_DLSSMode = { "DLSSMode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventSetDLSSMode_Parms, DLSSMode), Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::NewProp_DLSSMode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::NewProp_DLSSMode,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "SetDLSSMode", nullptr, nullptr, sizeof(DLSSLibrary_eventSetDLSSMode_Parms), Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics
	{
		struct DLSSLibrary_eventSetDLSSSharpness_Parms
		{
			float Sharpness;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Sharpness;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::NewProp_Sharpness = { "Sharpness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DLSSLibrary_eventSetDLSSSharpness_Parms, Sharpness), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::NewProp_Sharpness,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDLSSLibrary, nullptr, "SetDLSSSharpness", nullptr, nullptr, sizeof(DLSSLibrary_eventSetDLSSSharpness_Parms), Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UDLSSLibrary_NoRegister()
	{
		return UDLSSLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UDLSSLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDLSSLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_DLSSBlueprint,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDLSSLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDLSSLibrary_EnableDLAA, "EnableDLAA" }, // 519070389
		{ &Z_Construct_UFunction_UDLSSLibrary_GetDefaultDLSSMode, "GetDefaultDLSSMode" }, // 3872527018
		{ &Z_Construct_UFunction_UDLSSLibrary_GetDLSSMinimumDriverVersion, "GetDLSSMinimumDriverVersion" }, // 4127143009
		{ &Z_Construct_UFunction_UDLSSLibrary_GetDLSSMode, "GetDLSSMode" }, // 3796258090
		{ &Z_Construct_UFunction_UDLSSLibrary_GetDLSSModeInformation, "GetDLSSModeInformation" }, // 3982732404
		{ &Z_Construct_UFunction_UDLSSLibrary_GetDLSSScreenPercentageRange, "GetDLSSScreenPercentageRange" }, // 793683173
		{ &Z_Construct_UFunction_UDLSSLibrary_GetDLSSSharpness, "GetDLSSSharpness" }, // 410739415
		{ &Z_Construct_UFunction_UDLSSLibrary_GetSupportedDLSSModes, "GetSupportedDLSSModes" }, // 1284058695
		{ &Z_Construct_UFunction_UDLSSLibrary_IsDLAAEnabled, "IsDLAAEnabled" }, // 3277167740
		{ &Z_Construct_UFunction_UDLSSLibrary_IsDLSSModeSupported, "IsDLSSModeSupported" }, // 1320957051
		{ &Z_Construct_UFunction_UDLSSLibrary_IsDLSSSupported, "IsDLSSSupported" }, // 875098358
		{ &Z_Construct_UFunction_UDLSSLibrary_QueryDLSSSupport, "QueryDLSSSupport" }, // 773947983
		{ &Z_Construct_UFunction_UDLSSLibrary_SetDLSSMode, "SetDLSSMode" }, // 938588353
		{ &Z_Construct_UFunction_UDLSSLibrary_SetDLSSSharpness, "SetDLSSSharpness" }, // 660672678
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSLibrary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DLSSLibrary.h" },
		{ "ModuleRelativePath", "Public/DLSSLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDLSSLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDLSSLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDLSSLibrary_Statics::ClassParams = {
		&UDLSSLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDLSSLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDLSSLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDLSSLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDLSSLibrary, 3136763642);
	template<> DLSSBLUEPRINT_API UClass* StaticClass<UDLSSLibrary>()
	{
		return UDLSSLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDLSSLibrary(Z_Construct_UClass_UDLSSLibrary, &UDLSSLibrary::StaticClass, TEXT("/Script/DLSSBlueprint"), TEXT("UDLSSLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDLSSLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
