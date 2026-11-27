#pragma once
#include "CoreMinimal.h"
#include "EPitJawState.generated.h"

UENUM(BlueprintType)
enum class EPitJawState : uint8 {
    Idle,
    Preparing,
    Lunging,
    Grabbing,
    Escaping,
    Relocating,
    Dead,
    Frozen,
};

