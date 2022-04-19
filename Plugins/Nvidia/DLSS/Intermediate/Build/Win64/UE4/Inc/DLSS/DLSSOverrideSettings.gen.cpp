// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DLSS/Public/DLSSOverrideSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDLSSOverrideSettings() {}
// Cross Module References
	DLSS_API UClass* Z_Construct_UClass_UDLSSOverrideSettings_NoRegister();
	DLSS_API UClass* Z_Construct_UClass_UDLSSOverrideSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_DLSS();
	DLSS_API UEnum* Z_Construct_UEnum_DLSS_EDLSSSettingOverride();
// End Cross Module References
	void UDLSSOverrideSettings::StaticRegisterNativesUDLSSOverrideSettings()
	{
	}
	UClass* Z_Construct_UClass_UDLSSOverrideSettings_NoRegister()
	{
		return UDLSSOverrideSettings::StaticClass();
	}
	struct Z_Construct_UClass_UDLSSOverrideSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EnableDLSSInEditorViewportsOverride_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableDLSSInEditorViewportsOverride_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EnableDLSSInEditorViewportsOverride;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EnableDLSSInPlayInEditorViewportsOverride_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EnableDLSSInPlayInEditorViewportsOverride;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData[];
#endif
		static void NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowDLSSIncompatiblePluginsToolsWarnings;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ShowDLSSSDebugOnScreenMessages_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShowDLSSSDebugOnScreenMessages_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ShowDLSSSDebugOnScreenMessages;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDLSSOverrideSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_DLSS,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DLSSOverrideSettings.h" },
		{ "ModuleRelativePath", "Public/DLSSOverrideSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "DLSSOverrideSettings" },
		{ "ModuleRelativePath", "Public/DLSSOverrideSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride = { "EnableDLSSInEditorViewportsOverride", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDLSSOverrideSettings, EnableDLSSInEditorViewportsOverride), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "DLSSOverrideSettings" },
		{ "ModuleRelativePath", "Public/DLSSOverrideSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride = { "EnableScreenpercentageManipulationInDLSSEditorViewportsOverride", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDLSSOverrideSettings, EnableScreenpercentageManipulationInDLSSEditorViewportsOverride), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "DLSSOverrideSettings" },
		{ "ModuleRelativePath", "Public/DLSSOverrideSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride = { "EnableDLSSInPlayInEditorViewportsOverride", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDLSSOverrideSettings, EnableDLSSInPlayInEditorViewportsOverride), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "DLSSOverrideSettings" },
		{ "ModuleRelativePath", "Public/DLSSOverrideSettings.h" },
	};
#endif
	void Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_SetBit(void* Obj)
	{
		((UDLSSOverrideSettings*)Obj)->bShowDLSSIncompatiblePluginsToolsWarnings = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings = { "bShowDLSSIncompatiblePluginsToolsWarnings", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UDLSSOverrideSettings), &Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "DLSSOverrideSettings" },
		{ "ModuleRelativePath", "Public/DLSSOverrideSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages = { "ShowDLSSSDebugOnScreenMessages", nullptr, (EPropertyFlags)0x0010000000004005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UDLSSOverrideSettings, ShowDLSSSDebugOnScreenMessages), Z_Construct_UEnum_DLSS_EDLSSSettingOverride, METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDLSSOverrideSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInEditorViewportsOverride,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableScreenpercentageManipulationInDLSSEditorViewportsOverride,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_EnableDLSSInPlayInEditorViewportsOverride,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_bShowDLSSIncompatiblePluginsToolsWarnings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDLSSOverrideSettings_Statics::NewProp_ShowDLSSSDebugOnScreenMessages,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDLSSOverrideSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDLSSOverrideSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDLSSOverrideSettings_Statics::ClassParams = {
		&UDLSSOverrideSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDLSSOverrideSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::PropPointers),
		0,
		0x001000E4u,
		METADATA_PARAMS(Z_Construct_UClass_UDLSSOverrideSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDLSSOverrideSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDLSSOverrideSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDLSSOverrideSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDLSSOverrideSettings, 953777364);
	template<> DLSS_API UClass* StaticClass<UDLSSOverrideSettings>()
	{
		return UDLSSOverrideSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDLSSOverrideSettings(Z_Construct_UClass_UDLSSOverrideSettings, &UDLSSOverrideSettings::StaticClass, TEXT("/Script/DLSS"), TEXT("UDLSSOverrideSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDLSSOverrideSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
