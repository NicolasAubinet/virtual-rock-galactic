#include "StaticMeshCarverComponent.h"

UStaticMeshCarverComponent::UStaticMeshCarverComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHiddenInGame = true;
    this->OverrideMaterials.AddDefaulted(1);
    this->StaticMeshCarver = NULL;
    this->TerrainMaterial = NULL;
    this->Filter = ECarveFilterType::ReplaceAll;
}

void UStaticMeshCarverComponent::Carve() {
}


