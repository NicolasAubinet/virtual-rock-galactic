#include "HeavyParticleCannon.h"
#include "NiagaraComponent.h"
#include "DamageComponent.h"
#include "FSDAudioComponent.h"
#include "FirstPersonNiagaraComponent.h"
#include "Net/UnrealNetwork.h"
#include "ReflectionHitscanComponent.h"
#include "StickyFlameSpawner.h"

AHeavyParticleCannon::AHeavyParticleCannon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShieldChargingSound = NULL;
    this->ShieldOverchargingSound = NULL;
    this->ShieldSoundRandomStartMax = 0.00f;
    this->ShieldSoundFadeTime = 0.25f;
    this->ShieldTransferAudio = CreateDefaultSubobject<UFSDAudioComponent>(TEXT("ShieldTransferAudio"));
    this->CurrentTargetSound = ETargetSound::EStopShooting;
    this->ActiveShieldCue = NULL;
    this->Damage = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
    this->HitscanComponent = CreateDefaultSubobject<UReflectionHitscanComponent>(TEXT("ReflectionHitscanComponent"));
    this->StickyFlamesSpawner = CreateDefaultSubobject<UStickyFlameSpawner>(TEXT("StickyFlames"));
    this->FirstPersonBeam = CreateDefaultSubobject<UFirstPersonNiagaraComponent>(TEXT("FirstPersonBeam"));
    this->FirstPersonLaserSight = CreateDefaultSubobject<UFirstPersonNiagaraComponent>(TEXT("FirstPersonLaserSight"));
    this->ThirdPersonBeam = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ThirdPersonBeam"));
    this->BeamHitLocationGenericSound = NULL;
    this->BeamHitLocationEnemySound = NULL;
    this->BeamHitLocationEnemy_Local_Sound = NULL;
    this->BeamHitSoundFadeSwitchTime = 0.10f;
    this->BeamHitLocationTailSound = NULL;
    this->BoosterModuleActivated = NULL;
    this->ReflectedBeam = NULL;
    this->ReflectedBeam_PhotoSensitive = NULL;
    this->ReflectedLaserSight = NULL;
    this->ImpactParticle = NULL;
    this->ImpactParticle_PhotoSensitive = NULL;
    this->ProjectionModuleParticle = NULL;
    this->bReloadOnButtonRelease = false;
    this->MinTimeBetweenBiomassGain = 0.25f;
    this->BulkyBeam = false;
    this->NormalBeamWidth = 3.00f;
    this->BulkyBeamWidth = 6.00f;
    this->ExtraRadialDamagePerSec = 0.00f;
    this->ExtraRadialRangePerSec = 0.00f;
    this->CancelCostPercentage = 0.20f;
    this->ChargeupTime = 0.10f;
    this->StartChargeSound = NULL;
    this->IsNewDecalBeam = true;
    this->ProjectionModuleDamage = 0.00f;
    this->PlatformTerrainType = NULL;
    this->BoostActive = false;
    this->bReloadBoostsBeam = false;
    this->ExtraReloadTimeAfterBoost = 1.00f;
    this->BoostExtraAmmoCost = 2.00f;
    this->BeamDependentReloadDuration = 0.00f;
    this->bIsBeamActive = false;
    this->bDebugBeamHitSound = false;
    this->FirstPersonBeam->SetupAttachment(FPMesh);
    this->FirstPersonLaserSight->SetupAttachment(FPMesh);
    this->ShieldTransferAudio->SetupAttachment(RootComponent);
    this->ThirdPersonBeam->SetupAttachment(TPMesh);
}

void AHeavyParticleCannon::UpdateBeamsVisibility_Implementation(bool isBeamVisible) {
}

void AHeavyParticleCannon::UpdateBeam(const FReflectionTraceResult& Path) {
}

void AHeavyParticleCannon::ServerSetBoostActive_Implementation(bool newActive) {
}

void AHeavyParticleCannon::Server_SetBeamActive_Implementation(bool inIsBeamActive) {
}


void AHeavyParticleCannon::OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit) {
}

void AHeavyParticleCannon::OnRep_TargetSound() {
}

void AHeavyParticleCannon::OnRep_BoostActive() {
}

void AHeavyParticleCannon::OnRep_bIsBeamActive() {
}

void AHeavyParticleCannon::OnPlayerHealHit(FVector Location, AActor* Target) {
}

void AHeavyParticleCannon::OnOverhealRadialDamage(FVector Location, AActor* Target) {
}

void AHeavyParticleCannon::OnNonOverhealHit() {
}

void AHeavyParticleCannon::OnHitNothing() {
}

void AHeavyParticleCannon::OnHit(const FHitResult& Hit, bool bAlwaysPenetrate) {
}


void AHeavyParticleCannon::Client_AddAmmoOnKill_Implementation() {
}

void AHeavyParticleCannon::ChargeUpComplete() {
}


void AHeavyParticleCannon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AHeavyParticleCannon, CurrentTargetSound);
    DOREPLIFETIME(AHeavyParticleCannon, BoostActive);
    DOREPLIFETIME(AHeavyParticleCannon, bIsBeamActive);
}


