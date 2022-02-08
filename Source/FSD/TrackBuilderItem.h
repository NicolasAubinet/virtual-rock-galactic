#pragma once

#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "TrackBuilderItem.generated.h"

class ATrackBuilderSegment;
class UTrackBuilderConnectPoint;

UCLASS()
class FSD_API ATrackBuilderItem : public AAnimatedItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) ATrackBuilderSegment* NextSegment;
	UFUNCTION(BlueprintCallable) void ServerFinishPlacement(const FTransform& FinalLocation, class UTrackBuilderConnectPoint* ConnectPoint) {}
	UFUNCTION(BlueprintCallable) void FinishPlacement(const FTransform& FinalLocation, class UTrackBuilderConnectPoint* ConnectPoint) {}
};
