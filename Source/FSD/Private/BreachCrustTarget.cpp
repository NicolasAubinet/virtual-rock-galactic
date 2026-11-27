#include "BreachCrustTarget.h"
#include "Net/UnrealNetwork.h"

ABreachCrustTarget::ABreachCrustTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->LevelIndex = 0;
    this->AttachUsableTag = TEXT("CrustTargetAttach");
    this->ArmUsableTag = TEXT("CrustTargetArm");
    this->BeaconClass = NULL;
    this->CrackClass = NULL;
    this->DebugShowMarker = false;
    this->DebugSphereRadius = 300.00f;
    this->DebugBeamHeight = 4000.00f;
    this->DebugLineThickness = 8.00f;
    this->Beacon = NULL;
    this->AttachedCharge = NULL;
    this->Destroyed = false;
}

void ABreachCrustTarget::SetDebugShowCrackPath(bool Show) {
}

void ABreachCrustTarget::OnRep_Destroyed() {
}

void ABreachCrustTarget::OnRep_AttachedCharge() {
}


void ABreachCrustTarget::OnChargeDetonated(ABreachCharge* charge) {
}


void ABreachCrustTarget::OnAttachUsed(APlayerCharacter* User, EInputKeys Key) {
}

void ABreachCrustTarget::OnArmUsed(APlayerCharacter* User, EInputKeys Key) {
}

void ABreachCrustTarget::NotifyDestroyed() {
}

bool ABreachCrustTarget::IsDestroyed() const {
    return false;
}

bool ABreachCrustTarget::HasCharge() const {
    return false;
}

ABreachCharge* ABreachCrustTarget::GetAttachedCharge() const {
    return NULL;
}

bool ABreachCrustTarget::AttachCharge(ABreachCharge* charge) {
    return false;
}

bool ABreachCrustTarget::ArmCharge() {
    return false;
}

void ABreachCrustTarget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABreachCrustTarget, LevelIndex);
    DOREPLIFETIME(ABreachCrustTarget, Beacon);
    DOREPLIFETIME(ABreachCrustTarget, AttachedCharge);
    DOREPLIFETIME(ABreachCrustTarget, Destroyed);
}


