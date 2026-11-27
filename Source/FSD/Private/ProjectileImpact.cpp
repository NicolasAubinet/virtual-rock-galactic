#include "ProjectileImpact.h"

FProjectileImpact::FProjectileImpact() {
    this->PhysMat = NULL;
    this->BoneIndex = 0;
    this->bBlockingHit = false;
    this->TimeSinceActivation = 0.00f;
}

