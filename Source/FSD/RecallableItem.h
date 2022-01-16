#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "RecallableItem.generated.h"

UCLASS()
class FSD_API ARecallableItem : public AAnimatedItem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) void ServerSpawnItem(FVector Location, FRotator Rotation) {}
	UFUNCTION(BlueprintCallable) bool CanSpawnItem(FVector Location, FRotator Rotation) { return true; }
};
