#include "SpaceRigBlastShield.h"

ASpaceRigBlastShield::ASpaceRigBlastShield(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShieldAnimation = NULL;
    this->OpenAnimation = NULL;
}

void ASpaceRigBlastShield::OnShieldAnimNotify_Implementation(FName EventName) {
}

void ASpaceRigBlastShield::OnShieldAnimationStarted_Implementation(bool bClosing) {
}

void ASpaceRigBlastShield::OnShieldAnimationFinished_Implementation(bool bClosing) {
}


