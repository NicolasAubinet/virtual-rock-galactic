#include "BreachChargeBeacon.h"
#include "Net/UnrealNetwork.h"

ABreachChargeBeacon::ABreachChargeBeacon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->ChargePodClass = NULL;
    this->CalldownUsableTag = TEXT("CalldownButton");
    this->MaxGroundAdjustment = 2000.00f;
    this->State = EBreachBeaconState::Available;
    this->Pod = NULL;
    this->CrustTarget = NULL;
}

void ABreachChargeBeacon::SetCrustTarget(ABreachCrustTarget* Target) {
}

void ABreachChargeBeacon::OnRep_State() {
}

void ABreachChargeBeacon::OnPodStateChanged(ARessuplyPod* changedPod, ERessuplyPodState NewState) {
}

void ABreachChargeBeacon::OnCalldownUsed(APlayerCharacter* User, EInputKeys Key) {
}


ARessuplyPod* ABreachChargeBeacon::GetPod() const {
    return NULL;
}

ABreachCrustTarget* ABreachChargeBeacon::GetCrustTarget() const {
    return NULL;
}

EBreachBeaconState ABreachChargeBeacon::GetBeaconState() const {
    return EBreachBeaconState::Available;
}

bool ABreachChargeBeacon::CallDownPod() {
    return false;
}

void ABreachChargeBeacon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABreachChargeBeacon, State);
    DOREPLIFETIME(ABreachChargeBeacon, Pod);
    DOREPLIFETIME(ABreachChargeBeacon, CrustTarget);
}


