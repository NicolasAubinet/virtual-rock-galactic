#pragma once
#include "CoreMinimal.h"
#include "EBreachBeaconState.generated.h"

UENUM(BlueprintType)
enum class EBreachBeaconState : uint8 {
    Available,
    Called,
    Delivered,
};

