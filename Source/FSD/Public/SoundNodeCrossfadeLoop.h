#pragma once
#include "CoreMinimal.h"
#include "Sound/SoundNode.h"
#include "ECrossfadeLoopCurve.h"
#include "SoundNodeCrossfadeLoop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class FSD_API USoundNodeCrossfadeLoop : public USoundNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrossfadeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECrossfadeLoopCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomizeStartPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomStartMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomStartMax;
    
    USoundNodeCrossfadeLoop();

};

