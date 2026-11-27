#include "Projectile.h"
#include "FSDProjectileMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

AProjectile::AProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StickOnImpact = false;
    this->CourageFleeThreshold = 0.45f;
    this->UseArmorDamageBoneCheck = false;
    this->MovementComponent = CreateDefaultSubobject<UFSDProjectileMovementComponent>(TEXT("ProjectileComponent"));
}

AProjectileBase* AProjectile::SpawnProjectileFromSelf(UObject* WorldContextObject, TSubclassOf<AProjectileBase> ProjectileClass, FVector Origin, FRotator velocityDirection) {
    return NULL;
}

AProjectileBase* AProjectile::SpawnProjectile(UObject* WorldContextObject, TSubclassOf<AProjectileBase> ProjectileClass, APawn* projectileOwner, FVector Origin, FRotator velocityDirection) {
    return NULL;
}

AProjectileBase* AProjectile::SpawnBallisticProjectile(UObject* WorldContextObject, TSubclassOf<AProjectile> ProjectileClass, APawn* projectileOwner, FVector Origin, FVector Velocity) {
    return NULL;
}

void AProjectile::SetHomingTargetComponent(USceneComponent* HomingTargetComponent, float Delay) {
}

void AProjectile::Server_Stick_Implementation(const FProjectileImpact& Impact) {
}

void AProjectile::Server_DisableHoming_Implementation() {
}

void AProjectile::OnRep_StuckImpact() {
}

void AProjectile::OnRep_State(const FProjectileState& oldState) {
}

void AProjectile::OnPenetration(const FHitResult& HitResult) {
}

void AProjectile::OnImpact(const FHitResult& HitResult) {
}

void AProjectile::OnBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity) {
}

bool AProjectile::GetIsStuck() const {
    return false;
}

UFSDPhysicalMaterial* AProjectile::FindBoneIndexFromArmor(const FHitResult& HitResult, int32& outBoneIndex) const {
    return NULL;
}

void AProjectile::DisableHoming() {
}

void AProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AProjectile, StuckImpact);
    DOREPLIFETIME(AProjectile, State);
}


