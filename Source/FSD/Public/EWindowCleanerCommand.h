#pragma once
#include "CoreMinimal.h"
#include "EWindowCleanerCommand.generated.h"

UENUM(BlueprintType)
enum class EWindowCleanerCommand : uint8 {
    Left,
    Right,
    Clean,
};

