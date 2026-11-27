#pragma once
#include "CoreMinimal.h"
#include "OverclockUpgradeArray.generated.h"

class UOverclockUpgrade;

USTRUCT(BlueprintType)
struct FOverclockUpgradeArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UOverclockUpgrade*> Overclocks;
    
    FSD_API FOverclockUpgradeArray();
};

