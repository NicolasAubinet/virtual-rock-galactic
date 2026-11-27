#include "AssaultRifle.h"

AAssaultRifle::AAssaultRifle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FinalShotBonusDamage = 0.00f;
    this->KillsResetAccuracyDuration = 0.00f;
    this->KillsTriggersStatusEffect = false;
    this->KillTriggeredStatusEffect = NULL;
}

void AAssaultRifle::Server_SetFinalShotBonusActive_Implementation(bool Active) {
}




void AAssaultRifle::OnTimerElapsed() {
}

void AAssaultRifle::OnShotHit(const FHitResult& Hit, bool alwaysPenetrate) {
}

void AAssaultRifle::OnShotComplete() {
}

void AAssaultRifle::OnEnemyKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit) {
}

bool AAssaultRifle::IsFinalShotBonusActive() const {
    return false;
}

void AAssaultRifle::Client_ResetAccuracy_Implementation() {
}


