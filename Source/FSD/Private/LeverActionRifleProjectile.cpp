#include "LeverActionRifleProjectile.h"

ALeverActionRifleProjectile::ALeverActionRifleProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnDecalOnImpact = true;
    this->ImpactDecalSize = EImpactDecalSize::Small;
    this->CarveTerrainOnImpact = false;
    this->CarveDiameter = 100.00f;
    this->CarveNoise = 25.00f;
    this->CarveBurnThickness = 7.00f;
    this->CarveNormalOffset = 0.00f;
    this->CarveNormalSqueeze = 1.00f;
    this->CarveUsesBulletBurntMaterial = true;
    this->CarveBurntMaterialOverride = NULL;
    this->CarveDissolvesPlatforms = false;
    this->SpawnCarveParticles = true;
    this->CarveDebrisSize = 0.50f;
    this->PlayCarveCrumbleSound = true;
    this->TrailEffect = NULL;
    this->SuppressMeshOffsetBlend = true;
    this->TrailComponent = NULL;
    this->ValueDriveDuration = 1.00f;
}

void ALeverActionRifleProjectile::StopTrail() {
}

void ALeverActionRifleProjectile::StartValueDrive() {
}

void ALeverActionRifleProjectile::StartTrail() {
}

void ALeverActionRifleProjectile::SetTrailRotationOffset(FRotator Offset) {
}

void ALeverActionRifleProjectile::OnValueDriveUpdated_Implementation(float Value) {
}

FRotator ALeverActionRifleProjectile::GetTrailRotation() const {
    return FRotator{};
}


