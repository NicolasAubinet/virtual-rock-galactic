#include "ExplosiveSpoilsMutator.h"

UExplosiveSpoilsMutator::UExplosiveSpoilsMutator() {
    this->ExplosionRadius = 350.00f;
    this->ExplosionDamage = 40.00f;
    this->ExplosionEffectClass = NULL;
    this->CarveDiameterCM = 150.00f;
    this->CarveNoiseCM = 30.00f;
    this->CarveBurnThicknessCM = 10.00f;
    this->bHoarderClusterBombsEnabled = true;
    this->bGuaranteeSpawnAtMissionStart = false;
    this->bGuaranteeEncounterSpawnAtMissionStart = false;
}


