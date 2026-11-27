#pragma once
#include "CoreMinimal.h"
#include "EWindowCleanerPhase.generated.h"

UENUM(BlueprintType)
enum class EWindowCleanerPhase : uint8 {
    Idle,
    MovingLeft,
    MovingRight,
    Extending,
    Retracting,
    Celebrating,
};

