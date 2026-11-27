#include "ElectricField.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "StatusEffectTriggerComponent.h"

AElectricField::AElectricField(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->FieldRadius = 500.00f;
    this->FieldDuration = 6.00f;
    this->ElectricDamagePerTick = 0.00f;
    this->HeatDamagePerTick = 0.00f;
    this->DamageTickInterval = 0.50f;
    this->FriendlyFireDamageMultiplier = 0.50f;
    this->StaggerChance = 0.00f;
    this->StaggerDuration = 0.00f;
    this->FieldExtinguishTime = 1.50f;
    this->FieldLoopSound = NULL;
    this->DamageImpactSound = NULL;
    this->FilterOpenFrequency = 20000.00f;
    this->FilterEnvelopeCurve = NULL;
    this->FilterDuckedFrequency = 700.00f;
    this->FilterAttackTime = 0.04f;
    this->FilterReleaseTime = 0.50f;
    this->DamageAudioSpreadTime = 0.10f;
    this->FieldAudioFadeOutTime = 1.00f;
    this->Root = (USceneComponent*)RootComponent;
    this->FieldCollider = CreateDefaultSubobject<USphereComponent>(TEXT("FieldCollider"));
    this->StatusTriggerComponent = CreateDefaultSubobject<UStatusEffectTriggerComponent>(TEXT("StatusEffectTrigger"));
    this->FieldAudio = NULL;
    this->ElectricDamageClass = NULL;
    this->HeatDamageClass = NULL;
    this->FieldCollider->SetupAttachment(RootComponent);
}



void AElectricField::OnRep_FieldRadius() {
}

void AElectricField::All_OnDamagedEnemies_Implementation(const TArray<FVector_NetQuantize>& Locations) {
}

void AElectricField::All_FieldExpired_Implementation() {
}

void AElectricField::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AElectricField, FieldRadius);
    DOREPLIFETIME(AElectricField, FieldDuration);
}


