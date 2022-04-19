// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DLSSBlueprint/Public/UDLSSMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUDLSSMode() {}
// Cross Module References
	DLSSBLUEPRINT_API UEnum* Z_Construct_UEnum_DLSSBlueprint_UDLSSMode();
	UPackage* Z_Construct_UPackage__Script_DLSSBlueprint();
// End Cross Module References
	static UEnum* UDLSSMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DLSSBlueprint_UDLSSMode, Z_Construct_UPackage__Script_DLSSBlueprint(), TEXT("UDLSSMode"));
		}
		return Singleton;
	}
	template<> DLSSBLUEPRINT_API UEnum* StaticEnum<UDLSSMode>()
	{
		return UDLSSMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_UDLSSMode(UDLSSMode_StaticEnum, TEXT("/Script/DLSSBlueprint"), TEXT("UDLSSMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DLSSBlueprint_UDLSSMode_Hash() { return 4142334688U; }
	UEnum* Z_Construct_UEnum_DLSSBlueprint_UDLSSMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DLSSBlueprint();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("UDLSSMode"), 0, Get_Z_Construct_UEnum_DLSSBlueprint_UDLSSMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "UDLSSMode::Off", (int64)UDLSSMode::Off },
				{ "UDLSSMode::Auto", (int64)UDLSSMode::Auto },
				{ "UDLSSMode::UltraQuality", (int64)UDLSSMode::UltraQuality },
				{ "UDLSSMode::Quality", (int64)UDLSSMode::Quality },
				{ "UDLSSMode::Balanced", (int64)UDLSSMode::Balanced },
				{ "UDLSSMode::Performance", (int64)UDLSSMode::Performance },
				{ "UDLSSMode::UltraPerformance", (int64)UDLSSMode::UltraPerformance },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Auto.Name", "UDLSSMode::Auto" },
				{ "Balanced.Name", "UDLSSMode::Balanced" },
				{ "ModuleRelativePath", "Public/UDLSSMode.h" },
				{ "Off.Name", "UDLSSMode::Off" },
				{ "Performance.Name", "UDLSSMode::Performance" },
				{ "Quality.Name", "UDLSSMode::Quality" },
				{ "UltraPerformance.Name", "UDLSSMode::UltraPerformance" },
				{ "UltraQuality.Name", "UDLSSMode::UltraQuality" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DLSSBlueprint,
				nullptr,
				"UDLSSMode",
				"UDLSSMode",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
