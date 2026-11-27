#include "ProximityMissionShoutComponent.h"

UProximityMissionShoutComponent::UProximityMissionShoutComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Shout = NULL;
    this->bLocalDwarfShout = false;
    this->Radius = 300.00f;
    this->bMeasureToParentSurface = false;
    this->CheckInterval = 0.50f;
    this->bPriority = true;
    this->CoolDown = -1.00f;
    this->bShareWithSameShout = false;
}

bool UProximityMissionShoutComponent::HasPlayed() const {
    return false;
}


