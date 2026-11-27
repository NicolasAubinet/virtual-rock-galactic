#include "TauntAffectedComponent.h"

UTauntAffectedComponent::UTauntAffectedComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TauntedEffect = NULL;
}

AActor* UTauntAffectedComponent::GetEffectCauser() const {
    return NULL;
}


