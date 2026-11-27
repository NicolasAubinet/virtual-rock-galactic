#pragma once
#include "CoreMinimal.h"
#include "ECoreCorruptionCrystalState.generated.h"

UENUM(BlueprintType)
enum class ECoreCorruptionCrystalState : uint8 {
    Default,
    Idle,
    Invulnerable,
    Vulnerable,
    DeathDisplay,
    Dead,
};

