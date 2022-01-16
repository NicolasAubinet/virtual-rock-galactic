#pragma once

#include "CoreMinimal.h"
#include "ItemAggregator.h"
#include "ItemPlacerAggregator.generated.h"

class AItem;
class AItemMarker;

UCLASS()
class FSD_API UItemPlacerAggregator : public UItemAggregator
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) AItem* Item;
	UPROPERTY(BlueprintReadOnly) FTransform LastPlacement;
	UPROPERTY(BlueprintReadOnly) bool bIsMarkerValid;
	UPROPERTY(BlueprintReadOnly) bool bIsPlacementActive;
	UPROPERTY(BlueprintReadOnly) bool bIsMarkerHidden;
	UPROPERTY(BlueprintReadOnly) bool bCanPlaceMarker;
	UPROPERTY(BlueprintReadOnly) AItemMarker* PlacementMarker;
};
