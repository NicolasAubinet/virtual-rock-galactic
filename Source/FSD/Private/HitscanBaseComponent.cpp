#include "HitscanBaseComponent.h"
#include "Net/UnrealNetwork.h"

UHitscanBaseComponent::UHitscanBaseComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpreadPerShot = 2.00f;
    this->SpawnGroundHitParticles = true;
    this->DamageComponent = NULL;
    this->UseDamageComponent = true;
    this->Damage = 0.00f;
    this->armorDamageMultiplier = 1.00f;
    this->DamageClass = NULL;
    this->WeakpointDamageMultiplier = 1.00f;
    this->MaxPenetrations = 0;
    this->ImpactDecalSize = EImpactDecalSize::Small;
    this->FriendlyFireModifier = 1.00f;
    this->UseDynamicSpread = false;
    this->MinSpread = 0.00f;
    this->MinSpreadWhenMoving = 0.00f;
    this->MinSpreadWhenSprinting = 0.00f;
    this->MaxSpread = 5.00f;
    this->SpreadRecoveryPerSecond = 5.00f;
    this->VerticalSpreadMultiplier = 1.00f;
    this->HorizontalSpredMultiplier = 1.00f;
    this->MaxVerticalSpread = 0.00f;
    this->MaxHorizontalSpread = 0.00f;
    this->RicochetBehavior = ERicochetBehavior::All;
    this->RicochetChance = 0.00f;
    this->RicochetOnWeakspotOnly = false;
    this->RicochetMaxRange = 1500.00f;
    this->ImpactSpawnActorClass = NULL;
    this->ImpactSpawnDistance = 0.00f;
    this->ImpactSpawnShotSound = NULL;
}

void UHitscanBaseComponent::Server_StopFire_Implementation() {
}

void UHitscanBaseComponent::Server_RemoveDebris_Implementation(int32 instance, int32 Component) {
}

float UHitscanBaseComponent::GetCurrentVerticalSpread() const {
    return 0.0f;
}

float UHitscanBaseComponent::GetCurrentHorizontalSpread() const {
    return 0.0f;
}

void UHitscanBaseComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UHitscanBaseComponent, CustomImpactDecal);
    DOREPLIFETIME(UHitscanBaseComponent, SpawnGroundHitParticles);
}


