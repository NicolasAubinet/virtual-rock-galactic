#include "LeverActionRifle.h"
#include "ProjectileLauncherComponent.h"

ALeverActionRifle::ALeverActionRifle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AttachSocketName = TEXT("Dwarf_HandL_AttachSocket");
    this->projectileLauncher = CreateDefaultSubobject<UProjectileLauncherComponent>(TEXT("projectileLauncher"));
    this->FinisherDuration = 0.50f;
    this->GunslingWindowMin = 0.30f;
    this->GunslingWindowMax = 0.50f;
    this->GunslingSuccessWindowMin = 0.30f;
    this->GunslingSuccessWindowMax = 0.50f;
    this->GunslingBlendOut = 0.10f;
    this->IdleBonusThreshold = 2.00f;
    this->IdleAccuracyBonusAmount = 0.00f;
    this->bIdleAccuracyBonusIsPercentage = false;
    this->IdleDamageBonusAmount = 0.00f;
    this->bIdleDamageBonusIsPercentage = false;
    this->ActiveGunslingMontage = NULL;
}

void ALeverActionRifle::Server_StartFinisher_Implementation(bool bIsComplete) {
}

void ALeverActionRifle::Server_GunslingSuccess_Implementation() {
}

void ALeverActionRifle::Multicast_PlayFinisher_Implementation(bool bIsComplete) {
}

void ALeverActionRifle::Multicast_GunslingSuccess_Implementation() {
}


