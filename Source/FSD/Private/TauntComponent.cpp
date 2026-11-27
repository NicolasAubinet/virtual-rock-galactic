#include "TauntComponent.h"

UTauntComponent::UTauntComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TauntRadius = 300.00f;
    this->TauntEffect = NULL;
    this->TauntBuffOwner = NULL;
    this->DamageResistanceEffectInstance = NULL;
    this->TauntDuration = 0.00f;
    this->TauntAttractivenessMultiplier = 3.00f;
    this->TauntBonusAttackerSlots = 16;
    this->TauntRescanInterval = 0.50f;
}

void UTauntComponent::OnOwnerStateChanged(ECharacterState NewState) {
}

void UTauntComponent::FindTargets() {
}


