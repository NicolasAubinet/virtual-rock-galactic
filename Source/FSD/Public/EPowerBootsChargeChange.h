#pragma once
#include "CoreMinimal.h"
#include "EPowerBootsChargeChange.generated.h"

UENUM(BlueprintType)
enum class EPowerBootsChargeChange : uint8 {
    Charged,
    Released,
    Cancelled,
    Overcharged,
};

