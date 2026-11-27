#pragma once
#include "CoreMinimal.h"
#include "ETargetSound.generated.h"

UENUM(BlueprintType)
enum class ETargetSound : uint8 {
    EStartShooting,
    EStopShooting,
    EShieldHealing,
    EShieldOverHealing = 4,
    ENotHittingAnything = 8,
};

