#include "ClusterBombProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "DamageComponent.h"
#include "ProjectileExplosion.h"

AClusterBombProjectile::AClusterBombProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
    this->Damage = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
    this->ProjectileExplosionComponent = CreateDefaultSubobject<UProjectileExplosion>(TEXT("ProjectileExplosion"));
    this->FuseTime = 5.00f;
    this->CarveDiameterCM = 400.00f;
    this->CarveNoiseCM = 50.00f;
    this->BurnThickness = 20.00f;
    this->OverrideMaterial = NULL;
    this->bLeaveBiomeMineral = false;
    this->ProjectileMesh->SetupAttachment(RootComponent);
}


