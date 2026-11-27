#pragma once
#include "CoreMinimal.h"
#include "ECrossfadeLoopCurve.generated.h"

UENUM(BlueprintType)
enum class ECrossfadeLoopCurve : uint8 {
    EqualPower,
    Linear,
};

