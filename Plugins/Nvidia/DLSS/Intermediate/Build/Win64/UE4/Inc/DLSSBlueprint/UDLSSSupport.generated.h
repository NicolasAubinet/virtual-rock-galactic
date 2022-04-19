// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DLSSBLUEPRINT_UDLSSSupport_generated_h
#error "UDLSSSupport.generated.h already included, missing '#pragma once' in UDLSSSupport.h"
#endif
#define DLSSBLUEPRINT_UDLSSSupport_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FSD_Plugins_Nvidia_DLSS_Source_DLSSBlueprint_Public_UDLSSSupport_h


#define FOREACH_ENUM_UDLSSSUPPORT(op) \
	op(UDLSSSupport::Supported) \
	op(UDLSSSupport::NotSupported) \
	op(UDLSSSupport::NotSupportedIncompatibleHardware) \
	op(UDLSSSupport::NotSupportedDriverOutOfDate) \
	op(UDLSSSupport::NotSupportedOperatingSystemOutOfDate) \
	op(UDLSSSupport::NotSupportedByPlatformAtBuildTime) \
	op(UDLSSSupport::NotSupportedIncompatibleAPICaptureToolActive) 

enum class UDLSSSupport : uint8;
template<> DLSSBLUEPRINT_API UEnum* StaticEnum<UDLSSSupport>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
