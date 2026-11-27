#include "RagdollImpactComponent.h"

URagdollImpactComponent::URagdollImpactComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinImpactVelocity = 1000.00f;
    this->DamagePerVelocityAboveMinimum = 0.50f;
    this->MaxDamage = 30.00f;
    this->Radius = 400.00f;
    this->GracePeriod = 0.30f;
    this->ShockwaveDamageComponentClass = NULL;
    this->ShockwaveEffectClass = NULL;
    this->ModerateImpactSound = NULL;
    this->HeavyImpactSound = NULL;
    this->HeavyImpactVelocity = 1200.00f;
    this->RagdollMesh = NULL;
    this->ShockwaveDamageComponent = NULL;
}

void URagdollImpactComponent::OnRagdollHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void URagdollImpactComponent::All_ShowShockwave_Implementation(const FVector_NetQuantize& Location, float ImpactVelocity) {
}


