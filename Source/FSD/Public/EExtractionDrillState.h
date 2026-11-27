#pragma once
#include "CoreMinimal.h"
#include "EExtractionDrillState.generated.h"

UENUM(BlueprintType)
enum class EExtractionDrillState : uint8 {
    WaitingToEnter,
    Entering,
    Blocked,
    Ready,
    WarmingUp,
    Drilling,
    Venting,
    AwaitingRepairs,
    FinalDrilling,
    PrepTakeoff,
    Departing,
};

