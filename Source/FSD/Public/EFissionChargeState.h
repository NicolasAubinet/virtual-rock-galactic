#pragma once
#include "CoreMinimal.h"
#include "EFissionChargeState.generated.h"

UENUM(BlueprintType)
enum class EFissionChargeState : uint8 {
    Idle,
    WindingUp,
    Charging,
    FullyCharged,
};

