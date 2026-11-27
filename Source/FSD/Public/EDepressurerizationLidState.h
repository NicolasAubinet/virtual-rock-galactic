#pragma once
#include "CoreMinimal.h"
#include "EDepressurerizationLidState.generated.h"

UENUM(BlueprintType)
enum class EDepressurerizationLidState : uint8 {
    Closed,
    Opening,
    Open,
    Closing,
};

