#pragma once
#include "CoreMinimal.h"
#include "FSDPhysicsActor.h"
#include "PhysicsBarrel.generated.h"

UCLASS(Abstract, Blueprintable)
class APhysicsBarrel : public AFSDPhysicsActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsKickedIntoHoop;
    
    APhysicsBarrel(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Explode();
    
};

