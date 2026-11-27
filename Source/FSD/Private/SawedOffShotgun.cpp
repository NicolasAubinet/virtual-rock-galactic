#include "SawedOffShotgun.h"
#include "DamageComponent.h"

ASawedOffShotgun::ASawedOffShotgun(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("DamageComponent"));
    this->ShockwaveDamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("ShockwaveDamage"));
    this->FearFactorOnFire = 0.00f;
    this->FearFactorOnFireRadius = 500.00f;
    this->ShotgunJumpEnabled = false;
    this->ShotgunJumpForce = 4000.00f;
    this->ShockwaveEnabled = false;
    this->ShockWaveDistance = 250.00f;
    this->IncendiaryDispersersRadius = 264.00f;
    this->IncendiaryDispersersLifetime = 3.00f;
    this->IncendiaryDispersersDistance = 400.00f;
}

void ASawedOffShotgun::SetShockWaveDamageComponent(UDamageComponent* Component) {
}



