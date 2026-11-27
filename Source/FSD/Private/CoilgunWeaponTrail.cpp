#include "CoilgunWeaponTrail.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "NiagaraComponent.h"
#include "DamageComponent.h"
#include "Net/UnrealNetwork.h"

ACoilgunWeaponTrail::ACoilgunWeaponTrail(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->Root = (USceneComponent*)RootComponent;
    this->Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
    this->Trail = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TrailNiagara"));
    this->DamageComponent = CreateDefaultSubobject<UDamageComponent>(TEXT("ExplosiveDamage"));
    this->LightningBoltStartOffset = 0.00f;
    this->LightningBoltDamageRadius = 100.00f;
    this->LightningBoltDamageScaler = 0.50f;
    this->SpanReadyFired = false;
    this->TrailHalgLength = 0.00f;
    this->SpawnFireTrail = false;
    this->FireEffect = NULL;
    this->ElectricEffect = NULL;
    this->Collision->SetupAttachment(RootComponent);
    this->Trail->SetupAttachment(RootComponent);
}


void ACoilgunWeaponTrail::OnRep_TrailHalfLength() {
}

void ACoilgunWeaponTrail::OnRep_SpawnFireTrail() {
}

void ACoilgunWeaponTrail::OnLightningBoltSpanReady_Implementation(const FVector& StartLocation, const FVector& EndLocation) {
}

void ACoilgunWeaponTrail::OnInited_Callback() {
}

void ACoilgunWeaponTrail::OnActorLeaveTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ACoilgunWeaponTrail::OnActorEnteredTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ACoilgunWeaponTrail::GetLightningBoltSpan(FVector& OutStart, FVector& OutEnd) const {
}

void ACoilgunWeaponTrail::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACoilgunWeaponTrail, TrailHalgLength);
    DOREPLIFETIME(ACoilgunWeaponTrail, SpawnFireTrail);
}


