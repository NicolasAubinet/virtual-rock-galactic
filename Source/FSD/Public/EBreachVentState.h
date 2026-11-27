#pragma once
#include "CoreMinimal.h"
#include "EBreachVentState.generated.h"

UENUM(BlueprintType)
enum class EBreachVentState : uint8 {
    Sealed,
    Vulnerable,
    Damaged,
    Broken,
};

