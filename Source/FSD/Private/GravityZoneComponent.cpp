#include "GravityZoneComponent.h"

UGravityZoneComponent::UGravityZoneComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PhysicsOnlyScanInterval = 0.25f;
    this->StatusEffect = NULL;
    this->EnterSound = NULL;
    this->ExitSound = NULL;
    this->JumpSound = NULL;
    this->MinJumpVelocityZ = 100.00f;
    this->InAirLoopSound = NULL;
    this->InAirModulationPreset = NULL;
    this->InAirMaxRandomStartTime = 2.00f;
    this->InAirFadeInTime = 0.15f;
    this->InAirFadeOutTime = 0.15f;
    this->InAirAudioComponent = NULL;
}

void UGravityZoneComponent::SetGravityFalloffCurve(const FRuntimeFloatCurve& NewCurve) {
}

void UGravityZoneComponent::HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void UGravityZoneComponent::HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

FRuntimeFloatCurve UGravityZoneComponent::GetGravityFalloffCurve() const {
    return FRuntimeFloatCurve{};
}


