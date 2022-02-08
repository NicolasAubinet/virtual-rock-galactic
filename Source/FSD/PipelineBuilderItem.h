#pragma once

#include "CoreMinimal.h"
#include "TrackBuilderItem.h"
#include "PipelineBuilderItem.generated.h"

class UItemPlacerAggregator;

UCLASS()
class FSD_API APipelineBuilderItem : public ATrackBuilderItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) UItemPlacerAggregator* SegmentPlacer;
};
