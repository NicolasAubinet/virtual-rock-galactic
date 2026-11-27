#include "CoreCorruptionCrystal.h"
#include "Components/AudioComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"
#include "CoreCorruptionPillarSpawnerComponent.h"
#include "DamageComponent.h"
#include "EnemyComponent.h"
#include "EnemyHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "PathfinderCollisionComponent.h"
#include "RotatingSceneComponent.h"

ACoreCorruptionCrystal::ACoreCorruptionCrystal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->Bobber = CreateDefaultSubobject<URotatingSceneComponent>(TEXT("BobbingComponent"));
    this->Rotator = CreateDefaultSubobject<URotatingSceneComponent>(TEXT("RotatorComponent"));
    this->CrystalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SKMeshComponent"));
    this->WeakpointCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("WeakpointCollisionComponent"));
    this->ShieldCollision = CreateDefaultSubobject<UPathfinderCollisionComponent>(TEXT("ShieldCollision"));
    this->ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
    this->KnockbackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("KnockbackTriggerComponent"));
    this->Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LightComponent"));
    this->LargeLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("LargeLightComponent"));
    this->EnergyParticles = CreateDefaultSubobject<UNiagaraComponent>(TEXT("EnergyParticleComponent"));
    this->InvulnerableParticles = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RockShieldComponent"));
    this->Health = CreateDefaultSubobject<UEnemyHealthComponent>(TEXT("HealthComponent"));
    this->PillarSpawner = CreateDefaultSubobject<UCoreCorruptionPillarSpawnerComponent>(TEXT("SpawnerComponent"));
    this->enemy = CreateDefaultSubobject<UEnemyComponent>(TEXT("EnemyComponent"));
    this->KnockbackDamage = CreateDefaultSubobject<UDamageComponent>(TEXT("KnockbackDamageComponent"));
    this->EndExplosionDamage = CreateDefaultSubobject<UDamageComponent>(TEXT("EndExplosionDamageComponent"));
    this->Rift = NULL;
    this->Pillar = NULL;
    this->BeamTargetParamName = TEXT("Beam_EndPosition");
    this->DeathRattle = NULL;
    this->InvulnerableOverride = NULL;
    this->WeakPointMaterial = NULL;
    this->AliveSound = CreateDefaultSubobject<UAudioComponent>(TEXT("AliveSound"));
    this->ShieldsUpCue = NULL;
    this->ShieldsDownCue = NULL;
    this->BeamShootSound = NULL;
    this->BeamImpactSound = NULL;
    this->DeathCue = NULL;
    this->PushBackSound = NULL;
    this->PushBackEffect = NULL;
    this->SpawnBeamEffect = NULL;
    this->SpawnBeamImpactEffect = NULL;
    this->ShieldBeamLifeTimeMaxParamName = TEXT("LifeTimeMax");
    this->ShieldBeamLifeTimeMinParamName = TEXT("LifeTimeMin");
    this->DeathDisplayTime = 3.00f;
    this->DeathIntoRiftTime = 0.25f;
    this->KnockBackInterval = 1.00f;
    this->BossHealthBarDelay = 2.00f;
    this->State = ECoreCorruptionCrystalState::Default;
    this->AliveSound->SetupAttachment(RootComponent);
    this->Bobber->SetupAttachment(RootComponent);
    this->CrystalMesh->SetupAttachment(Rotator);
    this->EnergyParticles->SetupAttachment(CrystalMesh);
    this->InvulnerableParticles->SetupAttachment(CrystalMesh);
    this->KnockbackSphere->SetupAttachment(ShieldCollision);
    this->LargeLight->SetupAttachment(CrystalMesh);
    this->Light->SetupAttachment(CrystalMesh);
    this->Rotator->SetupAttachment(Bobber);
    this->ShieldCollision->SetupAttachment(CrystalMesh);
    this->ShieldMesh->SetupAttachment(ShieldCollision);
    this->WeakpointCollision->SetupAttachment(CrystalMesh);
}



void ACoreCorruptionCrystal::ShowHealthBar() {
}

void ACoreCorruptionCrystal::SetState(ECoreCorruptionCrystalState NewState) {
}



void ACoreCorruptionCrystal::OnRep_State(ECoreCorruptionCrystalState oldState) {
}


void ACoreCorruptionCrystal::OnPillarSpawned(AActor* pillarSpawned) {
}

void ACoreCorruptionCrystal::OnPillarDestroyed(ACoreCorruptionPillar* pillarDestroyed) {
}

void ACoreCorruptionCrystal::OnNewHealthSegment(int32 currentSegment, int32 prevSegment) {
}

void ACoreCorruptionCrystal::OnExitedKnockbackZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ACoreCorruptionCrystal::OnEnteredKnockbackZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ACoreCorruptionCrystal::OnDeath(UHealthComponent* HealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& damageTags) {
}

void ACoreCorruptionCrystal::OnDamaged(float Damage, const FDamageData& DamageData, bool anyHealthLost) {
}

void ACoreCorruptionCrystal::All_ShowPillarSpawnEffects_Implementation(FVector_NetQuantize pillarStoneLocation) {
}

void ACoreCorruptionCrystal::All_PlayKnockbackEffect_Implementation() const {
}

void ACoreCorruptionCrystal::All_AddKnockback_Implementation(FVector_NetQuantize Direction, float force) {
}

void ACoreCorruptionCrystal::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACoreCorruptionCrystal, Rift);
    DOREPLIFETIME(ACoreCorruptionCrystal, Pillar);
    DOREPLIFETIME(ACoreCorruptionCrystal, State);
}


