#include "CoreCorruptionRift.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Net/UnrealNetwork.h"
#include "TerrainPlacementComponent.h"

ACoreCorruptionRift::ACoreCorruptionRift(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->InstancedSpikesRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SpikesRootComponent"));
    this->SpikeMeshes.AddDefaulted(3);
    this->SpikeLocationSpline = CreateDefaultSubobject<USplineComponent>(TEXT("SpikelocationComponent"));
    this->DebrisSpawner = NULL;
    this->CrystalSpawnPosition = CreateDefaultSubobject<USceneComponent>(TEXT("CrystalSpawnPosition"));
    this->CrystalDeathPosition = CreateDefaultSubobject<USceneComponent>(TEXT("CrystalDeathPosition"));
    this->terrainPlacement = CreateDefaultSubobject<UTerrainPlacementComponent>(TEXT("Placement"));
    this->BonesToSpawn = 50;
    this->Seed = -1;
    this->CrystalClass = NULL;
    this->CrystalDeathPosition->SetupAttachment(RootComponent);
    this->CrystalSpawnPosition->SetupAttachment(RootComponent);
    this->InstancedSpikesRoot->SetupAttachment(RootComponent);
    this->SpikeLocationSpline->SetupAttachment(InstancedSpikesRoot);
    this->terrainPlacement->SetupAttachment(RootComponent);
}

void ACoreCorruptionRift::SpawnSpikes() {
}


void ACoreCorruptionRift::OnRep_Seed() {
}


void ACoreCorruptionRift::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACoreCorruptionRift, Seed);
}


