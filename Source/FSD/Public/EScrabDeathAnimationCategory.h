#pragma once
#include "CoreMinimal.h"
#include "EScrabDeathAnimationCategory.generated.h"

UENUM(BlueprintType)
enum class EScrabDeathAnimationCategory : uint8 {
    NoAnimation,
    Melt,
    Cook,
    Burn,
};

