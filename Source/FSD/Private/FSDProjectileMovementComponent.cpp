#include "FSDProjectileMovementComponent.h"

UFSDProjectileMovementComponent::UFSDProjectileMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bShouldPenetrate = false;
    this->bPenetrateOverlaps = false;
    this->InvertIgnoreCollisionAgainst = false;
    this->AccelerationCurve = NULL;
    this->AccelerationMultiplier = 1.00f;
    this->MaxPropulsionTime = 0.00f;
    this->bCancelPenetration = false;
}

void UFSDProjectileMovementComponent::OnUpdatedComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


