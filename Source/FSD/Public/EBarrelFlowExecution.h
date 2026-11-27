#pragma once
#include "CoreMinimal.h"
#include "EBarrelFlowExecution.generated.h"

UENUM(BlueprintType)
enum class EBarrelFlowExecution : uint8 {
    PlayerIsValid,
    PlayerIsNotValid,
};

