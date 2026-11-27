#include "ExplosiveCritterComponent.h"
#include "Templates/SubclassOf.h"

UExplosiveCritterComponent::UExplosiveCritterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SourceMutator = NULL;
    this->TriggerDelay = 0.00f;
    this->bGoldCrater = false;
    this->NumClusterBombs = 0;
}

void UExplosiveCritterComponent::TriggerExplosion() {
}

void UExplosiveCritterComponent::All_PlayExplosionEffect_Implementation(TSubclassOf<UExplosiveSpoilsEffect> EffectClass, FVector_NetQuantize Location, UMaterialInstance* DebrisMaterial, UTerrainMaterial* RockMaterial) {
}


