#include "BarrelSpawner.h"
#include "Net/UnrealNetwork.h"

ABarrelSpawner::ABarrelSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BarrelCount = 0;
}



void ABarrelSpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABarrelSpawner, BarrelCount);
}


