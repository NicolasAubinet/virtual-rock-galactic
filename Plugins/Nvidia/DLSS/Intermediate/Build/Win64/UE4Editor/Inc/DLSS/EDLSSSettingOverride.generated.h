// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DLSS_EDLSSSettingOverride_generated_h
#error "EDLSSSettingOverride.generated.h already included, missing '#pragma once' in EDLSSSettingOverride.h"
#endif
#define DLSS_EDLSSSettingOverride_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FSD_Plugins_Nvidia_DLSS_Source_DLSS_Public_EDLSSSettingOverride_h


#define FOREACH_ENUM_EDLSSSETTINGOVERRIDE(op) \
	op(EDLSSSettingOverride::Enabled) \
	op(EDLSSSettingOverride::Disabled) \
	op(EDLSSSettingOverride::UseProjectSettings) 

enum class EDLSSSettingOverride : uint8;
template<> DLSS_API UEnum* StaticEnum<EDLSSSettingOverride>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
