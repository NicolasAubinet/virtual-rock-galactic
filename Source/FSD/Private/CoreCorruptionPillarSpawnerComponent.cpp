#include "CoreCorruptionPillarSpawnerComponent.h"
#include "Net/UnrealNetwork.h"

UCoreCorruptionPillarSpawnerComponent::UCoreCorruptionPillarSpawnerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->spawned = NULL;
    this->PillarClass = NULL;
    this->Positioning = NULL;
    this->SpawnInterval = 0.00f;
    this->SpawnDeviation = 0.00f;
    this->InitialSpawnDelay = 0.00f;
    this->AmountToSpawn = 0;
    this->SpawnOneAtATime = false;
    this->DisallowSpawning = false;
}

void UCoreCorruptionPillarSpawnerComponent::StopSpawning() {
}

void UCoreCorruptionPillarSpawnerComponent::StartSpawning() {
}

void UCoreCorruptionPillarSpawnerComponent::SpawnPillar() {
}

void UCoreCorruptionPillarSpawnerComponent::PreFetchSpawnLocations(const FVector& Origin) {
}

void UCoreCorruptionPillarSpawnerComponent::OnRep_Spawned() {
}

void UCoreCorruptionPillarSpawnerComponent::OnPillarDestroyed(ACoreCorruptionPillar* Pillar) {
}

ACoreCorruptionPillar* UCoreCorruptionPillarSpawnerComponent::GetPillar() const {
    return NULL;
}

bool UCoreCorruptionPillarSpawnerComponent::CollectSpawnLocations(const FVector& Origin, TArray<FTransform> fallbackTransforms) {
    return false;
}

void UCoreCorruptionPillarSpawnerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UCoreCorruptionPillarSpawnerComponent, spawned);
}


