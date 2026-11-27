#include "DroneLauncherItem.h"
#include "Net/UnrealNetwork.h"
#include "ProjectileLauncherComponent.h"

ADroneLauncherItem::ADroneLauncherItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->projectileLauncher = CreateDefaultSubobject<UProjectileLauncherComponent>(TEXT("projectileLauncher"));
    this->UnequippedReturnSocketName = TEXT("Dwarf_ArmR22Socket");
    this->ActiveDroneCount = 0;
}

void ADroneLauncherItem::Server_RequestAllDronesReturn_Implementation() {
}

void ADroneLauncherItem::OnDroneSpawned(AProjectileBase* Projectile) {
}

void ADroneLauncherItem::OnDroneReturned(AProjectile* DroneProjectile) {
}

void ADroneLauncherItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADroneLauncherItem, ActiveDroneCount);
}


