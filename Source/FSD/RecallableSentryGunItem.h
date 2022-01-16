#pragma once

#include "CoreMinimal.h"
#include "RecallableItem.h"
#include "RecallableSentryGunItem.generated.h"

class UItemPlacerAggregator;
class ARecallableSentryGun;

UCLASS()
class FSD_API ARecallableSentryGunItem : public ARecallableItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite) int32 MaxSentryCount;
	UPROPERTY(BlueprintReadWrite) UItemPlacerAggregator* ItemPlacer;

	UFUNCTION(BlueprintCallable) bool AreAllSentriesPlaced() { return true; }
	UFUNCTION(BlueprintCallable) TArray<ARecallableSentryGun*> GetActiveSentryGuns() { return TArray<ARecallableSentryGun*>{}; }
};
