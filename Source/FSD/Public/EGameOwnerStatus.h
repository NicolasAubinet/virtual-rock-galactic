#pragma once
#include "CoreMinimal.h"
#include "EGameOwnerStatus.generated.h"

UENUM(BlueprintType)
enum class EGameOwnerStatus : uint8 {
    Supporter,
    ContentCreator,
    Translator,
    Developer,
    Modder,
    EGameOwnerStatus_Max = 255 UMETA(Hidden),
};

