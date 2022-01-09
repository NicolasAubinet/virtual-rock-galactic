#pragma once

#include "CoreMinimal.h"
#include "ThrowableItem.h"
#include "ShieldGeneratorItem.generated.h"

UCLASS()
class FSD_API AShieldGeneratorItem : public AThrowableItem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void GeneratorReturned() {}
	UFUNCTION(BlueprintCallable) bool GetIsRecharging() { return false; }
	UPROPERTY(BlueprintReadWrite) float RechargeProgress;
};
