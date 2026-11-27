#include "BreachChargePod.h"
#include "Net/UnrealNetwork.h"

ABreachChargePod::ABreachChargePod(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FuseTime = 5.00f;
    this->DestroyDelayAfterDetonation = 2.00f;
    this->ArmUsableTag = TEXT("ChargeArm");
    this->ChargeState = EBreachChargePodState::Dropping;
    this->CrustTarget = NULL;
}

void ABreachChargePod::SetCrustTarget(ABreachCrustTarget* Target) {
}

void ABreachChargePod::OnRep_ChargeState() {
}

void ABreachChargePod::OnPodStateChanged(ARessuplyPod* changedPod, ERessuplyPodState NewState) {
}




void ABreachChargePod::OnArmUsed(APlayerCharacter* User, EInputKeys Key) {
}


float ABreachChargePod::GetFuseRemaining() const {
    return 0.0f;
}

ABreachCrustTarget* ABreachChargePod::GetCrustTarget() const {
    return NULL;
}

EBreachChargePodState ABreachChargePod::GetChargeState() const {
    return EBreachChargePodState::Dropping;
}

void ABreachChargePod::Detonate() {
}

bool ABreachChargePod::Arm() {
    return false;
}

void ABreachChargePod::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABreachChargePod, ChargeState);
    DOREPLIFETIME(ABreachChargePod, CrustTarget);
}


