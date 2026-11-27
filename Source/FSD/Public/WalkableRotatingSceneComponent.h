#pragma once
#include "CoreMinimal.h"
#include "RotatingSceneComponent.h"
#include "WalkableRotatingSceneComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWalkableRotatingSceneComponent : public URotatingSceneComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinAnchorDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnchorProximityDistance;
    
public:
    UWalkableRotatingSceneComponent(const FObjectInitializer& ObjectInitializer);

};

