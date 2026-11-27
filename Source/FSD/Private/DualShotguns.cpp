#include "DualShotguns.h"
#include "Net/UnrealNetwork.h"

ADualShotguns::ADualShotguns(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FireModeSwitchTime = 0.15f;
    this->bSwitchingFireMode = false;
    this->MuzzleParticles_AltFire = NULL;
    this->TPMuzzleParticles_AltFire = NULL;
    this->FireSound_AltFire = NULL;
    this->MuzzleParticles_BaseFire = NULL;
    this->TPMuzzleParticles_BaseFire = NULL;
    this->FireSound_BaseFire = NULL;
}

void ADualShotguns::Server_BeginSwitchFireMode_Implementation() {
}


void ADualShotguns::OnRep_SwitchingFireMode() {
}

void ADualShotguns::All_SwitchFireModeCompleted_Implementation() {
}

void ADualShotguns::All_BeginSwitchFireMode_Implementation(bool bToAltFireMode) {
}

void ADualShotguns::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADualShotguns, bSwitchingFireMode);
}


