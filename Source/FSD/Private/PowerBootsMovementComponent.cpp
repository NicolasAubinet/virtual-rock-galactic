#include "PowerBootsMovementComponent.h"
#include "Net/UnrealNetwork.h"

UPowerBootsMovementComponent::UPowerBootsMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Stage1HoldTime = 0.30f;
    this->Stage2HoldTime = 0.60f;
    this->Stage3HoldTime = 1.60f;
    this->Stage2JumpZVelocity = 1200.00f;
    this->OverchargeJumpMultiplier = 1.50f;
    this->Stage1JumpAlpha = 0.50f;
    this->MinImpactVelocity = 1000.00f;
    this->DamagePerVelocityAboveMinimum = 0.50f;
    this->Radius = 400.00f;
    this->ShockwaveDamageComponentClass = NULL;
    this->EnemyImpactGracePeriod = 0.10f;
    this->FallDamageReductionStat = NULL;
    this->FallDamageReduction = 0.50f;
    this->AirControlMultiplier = 1.50f;
    this->LedgeClimbVelocityMultiplier = 1.41f;
    this->ChargeEffectClass = NULL;
    this->JumpEffectClass = NULL;
    this->ShockwaveEffectClass = NULL;
    this->ChargeSound = NULL;
    this->ChargedLoopSound = NULL;
    this->Stage1LaunchSound = NULL;
    this->Stage2LaunchSound = NULL;
    this->OverchargeLaunchSound = NULL;
    this->ModerateImpactSound = NULL;
    this->HeavyImpactSound = NULL;
    this->HeavyImpactVelocity = 1200.00f;
    this->ChargeDelay = 0.20f;
    this->Character = NULL;
    this->ChargeEffect = NULL;
    this->ChargeWidget = NULL;
    this->ShockwaveDamageComponent = NULL;
    this->ChargeAudio = NULL;
    this->ChargedLoopAudio = NULL;
}

void UPowerBootsMovementComponent::Server_SetChargeStage_Implementation(uint8 Stage, EPowerBootsChargeChange reason) {
}

void UPowerBootsMovementComponent::OnShockwaveTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* Component, UFSDPhysicalMaterial* PhysicalMaterial) {
}

void UPowerBootsMovementComponent::OnShockwaveComplete() {
}

void UPowerBootsMovementComponent::OnRep_ChargeState(FPowerBootsChargeState oldState) {
}

void UPowerBootsMovementComponent::OnLanded(const FHitResult& Hit) {
}

void UPowerBootsMovementComponent::OnJumpReleased() {
}

void UPowerBootsMovementComponent::OnJumpPressed() {
}

void UPowerBootsMovementComponent::OnCharacterStateChanged(ECharacterState NewState) {
}

void UPowerBootsMovementComponent::All_ShowShockwave_Implementation(const FVector_NetQuantize& Location, const FRotator& Rotation, float ImpactVelocity) {
}

void UPowerBootsMovementComponent::All_ShowChargedJump_Implementation(uint8 Stage) {
}

void UPowerBootsMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPowerBootsMovementComponent, ChargeState);
}


