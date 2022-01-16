#pragma once

#include "CoreMinimal.h"
#include "CapacityBasedItemAggregator.h"
#include "CapacityHoldingItemAggregator.generated.h"

UCLASS()
class FSD_API UCapacityHoldingItemAggregator : public UCapacityBasedItemAggregator
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) int32 MaxAmmo;
	UPROPERTY(BlueprintReadOnly) int32 AmmoCount;
};
