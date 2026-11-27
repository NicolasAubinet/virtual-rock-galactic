#pragma once
#include "CoreMinimal.h"
#include "EBreachChargeState.generated.h"

UENUM(BlueprintType)
enum class EBreachChargeState : uint8 {
    Carriable,
    Attached,
    Armed,
    Detonated,
};

