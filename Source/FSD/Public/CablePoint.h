#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "ETrackBuildPlacementState.h"
#include "CablePoint.generated.h"

class ACableEnd;

USTRUCT(BlueprintType)
struct FCablePoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrackBuildPlacementState PlacementState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize EulerRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ACableEnd> CableEnd;
    
    FSD_API FCablePoint();
};

