#include "ElectricFieldSpawner.h"

UElectricFieldSpawner::UElectricFieldSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ElectricFieldClass = NULL;
    this->IncendiaryDamageClass = NULL;
}

AElectricField* UElectricFieldSpawner::SpawnElectricField(FVector Location, FVector Normal) {
    return NULL;
}


