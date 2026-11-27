#include "FearTheBeardComponent.h"

UFearTheBeardComponent::UFearTheBeardComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StunRadius = 300.00f;
    this->SlowEffectInstance = NULL;
    this->SlowEffect = NULL;
}


void UFearTheBeardComponent::FindTargets() {
}


