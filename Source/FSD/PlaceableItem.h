#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "PlaceableItem.generated.h"

class UItemPlacerAggregator;

UCLASS()
class FSD_API APlaceableItem : public AAnimatedItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite) UItemPlacerAggregator* ItemPlacer;

	UFUNCTION(BlueprintCallable) void Server_SpawnItem(FVector Location) {}
};
