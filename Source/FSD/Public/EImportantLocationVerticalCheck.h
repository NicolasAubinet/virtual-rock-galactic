#pragma once
#include "CoreMinimal.h"
#include "EImportantLocationVerticalCheck.generated.h"

UENUM(BlueprintType)
enum class EImportantLocationVerticalCheck : uint8 {
    None,
    Above,
    Below,
    AboveAndBelow,
};

