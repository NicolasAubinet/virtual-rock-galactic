#include "OptionalBloodPhysicalMaterial.h"

UOptionalBloodPhysicalMaterial::UOptionalBloodPhysicalMaterial() {
    this->ImpactDecals.AddDefaulted(3);
    this->MeleeImpactDecals.AddDefaulted(4);
    this->BloodlessImpactParticles = NULL;
}


