#include "CoilgunRicochetHitscanComponent.h"

UCoilgunRicochetHitscanComponent::UCoilgunRicochetHitscanComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UseDamageComponent = false;
    this->MaxRicochets = 2;
    this->EnemyPenetrationDepth = 100.00f;
    this->SurfaceOffset = 5.00f;
}


