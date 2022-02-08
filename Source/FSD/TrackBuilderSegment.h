#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackBuilderSegment.generated.h"

class UTrackBuilderConnectPoint;

UCLASS()
class FSD_API ATrackBuilderSegment : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable) UTrackBuilderConnectPoint* GetConnectPoint() { return nullptr; }
};
