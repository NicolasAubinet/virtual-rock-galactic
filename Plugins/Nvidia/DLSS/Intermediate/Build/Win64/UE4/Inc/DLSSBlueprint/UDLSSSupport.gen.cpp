// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DLSSBlueprint/Public/UDLSSSupport.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUDLSSSupport() {}
// Cross Module References
	DLSSBLUEPRINT_API UEnum* Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport();
	UPackage* Z_Construct_UPackage__Script_DLSSBlueprint();
// End Cross Module References
	static UEnum* UDLSSSupport_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport, Z_Construct_UPackage__Script_DLSSBlueprint(), TEXT("UDLSSSupport"));
		}
		return Singleton;
	}
	template<> DLSSBLUEPRINT_API UEnum* StaticEnum<UDLSSSupport>()
	{
		return UDLSSSupport_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_UDLSSSupport(UDLSSSupport_StaticEnum, TEXT("/Script/DLSSBlueprint"), TEXT("UDLSSSupport"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport_Hash() { return 2395428442U; }
	UEnum* Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DLSSBlueprint();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("UDLSSSupport"), 0, Get_Z_Construct_UEnum_DLSSBlueprint_UDLSSSupport_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "UDLSSSupport::Supported", (int64)UDLSSSupport::Supported },
				{ "UDLSSSupport::NotSupported", (int64)UDLSSSupport::NotSupported },
				{ "UDLSSSupport::NotSupportedIncompatibleHardware", (int64)UDLSSSupport::NotSupportedIncompatibleHardware },
				{ "UDLSSSupport::NotSupportedDriverOutOfDate", (int64)UDLSSSupport::NotSupportedDriverOutOfDate },
				{ "UDLSSSupport::NotSupportedOperatingSystemOutOfDate", (int64)UDLSSSupport::NotSupportedOperatingSystemOutOfDate },
				{ "UDLSSSupport::NotSupportedByPlatformAtBuildTime", (int64)UDLSSSupport::NotSupportedByPlatformAtBuildTime },
				{ "UDLSSSupport::NotSupportedIncompatibleAPICaptureToolActive", (int64)UDLSSSupport::NotSupportedIncompatibleAPICaptureToolActive },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/UDLSSSupport.h" },
				{ "NotSupported.Name", "UDLSSSupport::NotSupported" },
				{ "NotSupportedByPlatformAtBuildTime.Name", "UDLSSSupport::NotSupportedByPlatformAtBuildTime" },
				{ "NotSupportedDriverOutOfDate.Name", "UDLSSSupport::NotSupportedDriverOutOfDate" },
				{ "NotSupportedIncompatibleAPICaptureToolActive.Name", "UDLSSSupport::NotSupportedIncompatibleAPICaptureToolActive" },
				{ "NotSupportedIncompatibleHardware.Name", "UDLSSSupport::NotSupportedIncompatibleHardware" },
				{ "NotSupportedOperatingSystemOutOfDate.Name", "UDLSSSupport::NotSupportedOperatingSystemOutOfDate" },
				{ "Supported.Name", "UDLSSSupport::Supported" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DLSSBlueprint,
				nullptr,
				"UDLSSSupport",
				"UDLSSSupport",
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
