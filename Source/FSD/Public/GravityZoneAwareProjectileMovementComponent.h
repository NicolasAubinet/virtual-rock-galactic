#pragma once
#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GravityZoneAwareProjectileMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UGravityZoneAwareProjectileMovementComponent : public UProjectileMovementComponent {
    GENERATED_BODY()
public:
    UGravityZoneAwareProjectileMovementComponent(const FObjectInitializer& ObjectInitializer);

};

