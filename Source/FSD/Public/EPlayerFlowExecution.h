#pragma once
#include "CoreMinimal.h"
#include "EPlayerFlowExecution.generated.h"

UENUM(BlueprintType)
enum class EPlayerFlowExecution : uint8 {
    IsCarryingNothing,
    IsCarryingSpaceball,
    IsCarryingDatacell,
};

