#include "WalkableRotatingSceneComponent.h"

UWalkableRotatingSceneComponent::UWalkableRotatingSceneComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinAnchorDelay = 2.00f;
    this->AnchorProximityDistance = 3000.00f;
}


