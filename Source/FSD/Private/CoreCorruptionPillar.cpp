#include "CoreCorruptionPillar.h"
#include "Components/AudioComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"
#include "MeshCarverComponent.h"
#include "TerrainDetectComponent.h"
#include "TerrainPlacementComponent.h"

ACoreCorruptionPillar::ACoreCorruptionPillar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->SpaceCarver = CreateDefaultSubobject<UMeshCarverComponent>(TEXT("SpaceCarver"));
    this->PillarCarver = CreateDefaultSubobject<UMeshCarverComponent>(TEXT("PillarCarver"));
    this->DestroyPillarCarver = CreateDefaultSubobject<UMeshCarverComponent>(TEXT("DestroyPillarCarver"));
    this->PillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
    this->StoneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("StoneRoot"));
    this->StoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StoneMesh"));
    this->TerrainDetector = CreateDefaultSubobject<UTerrainDetectComponent>(TEXT("TerrainDetector"));
    this->Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
    this->terrainPlacement = CreateDefaultSubobject<UTerrainPlacementComponent>(TEXT("terrainPlacement"));
    this->PillarParticles = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PillarParticles"));
    this->SpawnEffect = NULL;
    this->PillarDestroyedEffect = NULL;
    this->StoneDestroyedEffect = NULL;
    this->ShieldBeamSpline = CreateDefaultSubobject<USplineComponent>(TEXT("ShieldBeamSpline"));
    this->ShieldBeam = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ShieldBeam"));
    this->ShieldBeamLifeTimeMaxDistanceMult = 0.01f;
    this->ShieldBeamLifeTimeMinDistanceMult = 0.00f;
    this->RockIdleSound = CreateDefaultSubobject<UAudioComponent>(TEXT("RockIdleSound"));
    this->PillarDestroyedSound = NULL;
    this->StoneDestroyedSound = NULL;
    this->DeathRattle = NULL;
    this->bCarvable = false;
    this->DestroyPillarCarver->SetupAttachment(RootComponent);
    this->Light->SetupAttachment(StoneMesh);
    this->PillarCarver->SetupAttachment(RootComponent);
    this->PillarMesh->SetupAttachment(RootComponent);
    this->PillarParticles->SetupAttachment(RootComponent);
    this->RockIdleSound->SetupAttachment(RootComponent);
    this->ShieldBeam->SetupAttachment(RootComponent);
    this->ShieldBeamSpline->SetupAttachment(RootComponent);
    this->SpaceCarver->SetupAttachment(RootComponent);
    this->StoneMesh->SetupAttachment(StoneRoot);
    this->StoneRoot->SetupAttachment(RootComponent);
    this->TerrainDetector->SetupAttachment(StoneMesh);
    this->terrainPlacement->SetupAttachment(RootComponent);
}

void ACoreCorruptionPillar::OnCarvedFree(USceneComponent* Point) {
}


void ACoreCorruptionPillar::DestroyStone() {
}


void ACoreCorruptionPillar::All_DestroyPillar_Implementation() {
}



