#pragma once
#include "CoreMinimal.h"
#include "EBreachChargePodState.generated.h"

UENUM(BlueprintType)
enum class EBreachChargePodState : uint8 {
    Dropping,
    Landed,
    Armed,
    Detonated,
};

