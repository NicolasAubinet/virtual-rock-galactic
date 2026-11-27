#pragma once
#include "CoreMinimal.h"
#include "EShoutTriggerAudience.generated.h"

UENUM(BlueprintType)
enum class EShoutTriggerAudience : uint8 {
    EnteringDwarfOnly,
    Everyone,
    MissionControl,
};

