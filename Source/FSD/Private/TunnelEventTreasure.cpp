#include "TunnelEventTreasure.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ATunnelEventTreasure::ATunnelEventTreasure(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->Root = (USceneComponent*)RootComponent;
    this->TerrainDetectors.AddDefaulted(3);
    this->MeshComponent->SetupAttachment(RootComponent);
}


void ATunnelEventTreasure::OnTerrainPointRemoved(USceneComponent* Point) {
}

void ATunnelEventTreasure::EnableTerrainDetection() {
}


