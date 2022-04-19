// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DLSS/Public/EDLSSSettingOverride.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEDLSSSettingOverride() {}
// Cross Module References
	DLSS_API UEnum* Z_Construct_UEnum_DLSS_EDLSSSettingOverride();
	UPackage* Z_Construct_UPackage__Script_DLSS();
// End Cross Module References
	static UEnum* EDLSSSettingOverride_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DLSS_EDLSSSettingOverride, Z_Construct_UPackage__Script_DLSS(), TEXT("EDLSSSettingOverride"));
		}
		return Singleton;
	}
	template<> DLSS_API UEnum* StaticEnum<EDLSSSettingOverride>()
	{
		return EDLSSSettingOverride_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EDLSSSettingOverride(EDLSSSettingOverride_StaticEnum, TEXT("/Script/DLSS"), TEXT("EDLSSSettingOverride"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Hash() { return 2672109497U; }
	UEnum* Z_Construct_UEnum_DLSS_EDLSSSettingOverride()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DLSS();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EDLSSSettingOverride"), 0, Get_Z_Construct_UEnum_DLSS_EDLSSSettingOverride_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EDLSSSettingOverride::Enabled", (int64)EDLSSSettingOverride::Enabled },
				{ "EDLSSSettingOverride::Disabled", (int64)EDLSSSettingOverride::Disabled },
				{ "EDLSSSettingOverride::UseProjectSettings", (int64)EDLSSSettingOverride::UseProjectSettings },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Disabled.Name", "EDLSSSettingOverride::Disabled" },
				{ "Enabled.Name", "EDLSSSettingOverride::Enabled" },
				{ "ModuleRelativePath", "Public/EDLSSSettingOverride.h" },
				{ "UseProjectSettings.Name", "EDLSSSettingOverride::UseProjectSettings" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DLSS,
				nullptr,
				"EDLSSSettingOverride",
				"EDLSSSettingOverride",
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
