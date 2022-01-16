#pragma once

#include "CoreMinimal.h"
#include "ThrowableItem.h"
#include "ShieldGeneratorItem.generated.h"

class UCapacityHoldingItemAggregator;

UCLASS()
class FSD_API AShieldGeneratorItem : public AThrowableItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) UCapacityHoldingItemAggregator* ChargeCapacity;
	UPROPERTY(BlueprintReadOnly) UCapacityHoldingItemAggregator* CarryCapacity;
	UPROPERTY(BlueprintReadOnly) float RechargeProgress;
	UPROPERTY(BlueprintReadOnly) float RechargeDuration;

	UFUNCTION(BlueprintCallable) void GeneratorReturned() {}
	UFUNCTION(BlueprintCallable) bool GetIsRecharging() { return false; }
};
