#include "Scrab.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/AudioComponent.h"
#include "EnemyComponent.h"
#include "FrozenPawnImpactComponent.h"
#include "HitReactionComponent.h"
#include "IKComponent.h"
#include "OutlineComponent.h"
#include "PathfinderReactiveTerrainTrackerComponent.h"
#include "PawnAlertComponent.h"
#include "PawnStatsComponent.h"
#include "WalkAndFlyEnemyComponent.h"

AScrab::AScrab(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bNetLoadOnClient = false;
    this->WingAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("WingAudio"));
    this->EnemyComponent = CreateDefaultSubobject<UEnemyComponent>(TEXT("enemy"));
    this->outline = CreateDefaultSubobject<UOutlineComponent>(TEXT("outline"));
    this->WalkAndFly = CreateDefaultSubobject<UWalkAndFlyEnemyComponent>(TEXT("WalkAndFly"));
    this->PathfinderReactiveTerrainTracker = CreateDefaultSubobject<UPathfinderReactiveTerrainTrackerComponent>(TEXT("PathfinderReactiveTerrainTracker"));
    this->PawnStats = CreateDefaultSubobject<UPawnStatsComponent>(TEXT("PawnStats"));
    this->PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
    this->Alert = CreateDefaultSubobject<UPawnAlertComponent>(TEXT("Alert"));
    this->FrozenImpact = CreateDefaultSubobject<UFrozenPawnImpactComponent>(TEXT("FrozenImpact"));
    this->HitReactions = CreateDefaultSubobject<UHitReactionComponent>(TEXT("HitReactions"));
    this->IK = CreateDefaultSubobject<UIKComponent>(TEXT("IK"));
    this->TargetTrackingRotationSpeed = 10.00f;
    this->WingAudio->SetupAttachment(Mesh);
}



void AScrab::OnPathfinderStateChanged() {
}

void AScrab::OnFreezeImpact() {
}

void AScrab::OnDamageTaken(float amount) {
}

void AScrab::OnBugDeath(UHealthComponentBase* Health) {
}

void AScrab::All_Ragdoll_Implementation(const FVector_NetQuantize& Location, const FVector_NetQuantize& Impulse, uint8 BoneIndex) {
}

void AScrab::AddImpulseAndRagdoll(const FDamageData& DamageData) {
}


