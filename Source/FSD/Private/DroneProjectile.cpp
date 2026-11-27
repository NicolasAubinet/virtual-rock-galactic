#include "DroneProjectile.h"
#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DamageComponent.h"
#include "Net/UnrealNetwork.h"
#include "ProjectileExplosion.h"

ADroneProjectile::ADroneProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->HomingTarget = CreateDefaultSubobject<USphereComponent>(TEXT("HomingTarget"));
    this->ReturnTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("ReturnTrigger"));
    this->DroneLoop = CreateDefaultSubobject<UAudioComponent>(TEXT("DroneLoop"));
    this->Damage = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
    this->ProjectileExplosion = CreateDefaultSubobject<UProjectileExplosion>(TEXT("ProjectileExplosion"));
    this->DroneLaunchCue = NULL;
    this->DroneLauncher = NULL;
    this->MaxImpacts = 10;
    this->Impacts = 0;
    this->MaxFlightDuration = 7.00f;
    this->FlightDuration = 0.00f;
    this->MaxReturnDuration = 7.00f;
    this->ReturnDuration = 0.00f;
    this->bReturning = false;
    this->DroneLoop->SetupAttachment(RootComponent);
    this->HomingTarget->SetupAttachment(RootComponent);
    this->Mesh->SetupAttachment(RootComponent);
    this->ReturnTrigger->SetupAttachment(RootComponent);
}

void ADroneProjectile::Server_SetupHoming_Implementation(const FHitResult& NewHitResult) {
}

void ADroneProjectile::OnTargetDied(UHealthComponentBase* HealthComponent) {
}

void ADroneProjectile::OnRep_Returning() {
}

void ADroneProjectile::OnRep_HitResult() {
}

void ADroneProjectile::OnLauncherEquipStateChanged() {
}

void ADroneProjectile::OnHomingTargetBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}



UHealthComponentBase* ADroneProjectile::GetTargetHealthComponent() {
    return NULL;
}

AActor* ADroneProjectile::GetTarget() {
    return NULL;
}

void ADroneProjectile::DoReturnCheck(AActor* hitTarget) {
}

void ADroneProjectile::Client_NotifyReturnComplete_Implementation() {
}

void ADroneProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADroneProjectile, HitResult);
    DOREPLIFETIME(ADroneProjectile, bReturning);
}


