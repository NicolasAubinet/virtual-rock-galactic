#include "PawnAfflictionComponent.h"
#include "Net/UnrealNetwork.h"

UPawnAfflictionComponent::UPawnAfflictionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FrozenEffect = NULL;
    this->BurningEffect = NULL;
    this->EffectSize = EFrozenBitsSize::Medium;
    this->BaseEffectScale = 1.00f;
    this->UseDormancy = false;
    this->TimeToFlash = 0.00f;
}

void UPawnAfflictionComponent::PushAffliction(UPawnAffliction* Affliction, bool onlyIfNotActive) {
}

void UPawnAfflictionComponent::PopAffliction(UPawnAffliction* Affliction) {
}

void UPawnAfflictionComponent::OnDeath(UHealthComponentBase* HealthComponent) {
}

void UPawnAfflictionComponent::Multicast_OnStartFlashing_Implementation(UPawnAffliction* Affliction) {
}

bool UPawnAfflictionComponent::IsAfflictedBy(UPawnAffliction* Affliction) const {
    return false;
}

TArray<UPawnAffliction*> UPawnAfflictionComponent::GetActiveAfflictions() const {
    return TArray<UPawnAffliction*>();
}

void UPawnAfflictionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPawnAfflictionComponent, NetworkedAfflictions);
}


