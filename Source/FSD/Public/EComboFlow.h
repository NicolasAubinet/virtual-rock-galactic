#pragma once
#include "CoreMinimal.h"
#include "EComboFlow.generated.h"

UENUM(BlueprintType)
enum class EComboFlow : uint8 {
    Unchanged,
    ComboGained,
    ComboLost,
};

