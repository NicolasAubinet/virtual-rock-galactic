#include "PelletMultiplierProjectile.h"

APelletMultiplierProjectile::APelletMultiplierProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ExpectedHitRateDamage = 1.00f;
    this->ExpectedHitRateStagger = 1.00f;
}


