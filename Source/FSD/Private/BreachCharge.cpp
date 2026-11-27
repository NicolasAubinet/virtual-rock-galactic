#include "BreachCharge.h"
#include "Net/UnrealNetwork.h"

ABreachCharge::ABreachCharge(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FuseTime = 5.00f;
    this->DestroyDelayAfterDetonation = 2.00f;
    this->HideOnDetonation = true;
    this->State = EBreachChargeState::Carriable;
    this->AttachedTarget = NULL;
}

void ABreachCharge::OnRep_State() {
}






bool ABreachCharge::IsDeployed() const {
    return false;
}

void ABreachCharge::HandleCarriableDropped() {
}

float ABreachCharge::GetFuseRemaining() const {
    return 0.0f;
}

EBreachChargeState ABreachCharge::GetChargeState() const {
    return EBreachChargeState::Carriable;
}

AActor* ABreachCharge::GetAttachedTarget() const {
    return NULL;
}

void ABreachCharge::Detonate() {
}

bool ABreachCharge::AttachToTarget(AActor* Target) {
    return false;
}

bool ABreachCharge::Arm() {
    return false;
}

void ABreachCharge::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABreachCharge, State);
    DOREPLIFETIME(ABreachCharge, AttachedTarget);
}


