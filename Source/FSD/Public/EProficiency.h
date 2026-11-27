#pragma once
#include "CoreMinimal.h"
#include "EProficiency.generated.h"

UENUM(BlueprintType)
enum class EProficiency : uint8 {
    NoProficiency,
    CombatProficiency,
    SurvivalProficiency,
    MobilityProficiency = 4,
    ResourcefulnessProficiency = 8,
};

