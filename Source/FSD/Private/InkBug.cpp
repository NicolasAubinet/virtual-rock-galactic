#include "InkBug.h"
#include "EnemyLineOfSightComponent.h"
#include "Net/UnrealNetwork.h"
#include "OutlineComponent.h"

AInkBug::AInkBug(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LineOfSight = CreateDefaultSubobject<UEnemyLineOfSightComponent>(TEXT("LineOfSight"));
    this->outline = CreateDefaultSubobject<UOutlineComponent>(TEXT("outline"));
    this->PopSpawnActorClass = NULL;
    this->deathMontage = NULL;
    this->bApplyCamouflage = true;
    this->FleeMontage = NULL;
    this->HideMontage = NULL;
    this->ReFleeRadius = 800.00f;
    this->FarFleeExtraDistance = 800.00f;
    this->bPlayingFleeMontage = false;
    this->bFleeTellPlayed = false;
    this->bFarFleeing = false;
    this->bIsCamouflaged = false;
    this->CamouflageRenderMaterial = NULL;
    this->InkCloudClass = NULL;
    this->InkCloudSpeedBoost = NULL;
    this->InkCloudCooldown = 10.00f;
    this->InkCloudUntargetableDuration = 2.00f;
    this->bIsInkCloudUntargetable = false;
    this->bInkCloudPending = false;
    this->bInkCloudSpeedBoostPending = false;
}


void AInkBug::OnRep_IsCamouflaged() {
}

void AInkBug::OnHealthHit(float Damage, const FDamageData& DamageData, bool anyHealthLost) {
}

void AInkBug::OnHealthDeath(UHealthComponentBase* deadHealth) {
}

void AInkBug::OnFleeMontageEnded(UAnimMontage* Montage, bool interrupted) {
}

void AInkBug::OnFarFleeFinished(bool success) {
}


void AInkBug::OnDeathMontageBlendingOut(UAnimMontage* Montage, bool interrupted) {
}


bool AInkBug::HasLoot() const {
    return false;
}

UMaterialInterface* AInkBug::GetCachedMaterial() const {
    return NULL;
}

AResourceChunk* AInkBug::DropLoot(FVector Impulse, FVector DropOffset) {
    return NULL;
}

AActor* AInkBug::DropItem(FVector Impulse, FVector DropOffset) {
    return NULL;
}

void AInkBug::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AInkBug, bIsCamouflaged);
    DOREPLIFETIME(AInkBug, bIsInkCloudUntargetable);
}


