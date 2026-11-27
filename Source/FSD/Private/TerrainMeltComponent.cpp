#include "TerrainMeltComponent.h"

UTerrainMeltComponent::UTerrainMeltComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->meltRadius = 100.00f;
    this->MeltInterval = 1.00f;
    this->InitialMeltRadius = 50.00f;
    this->MeltStepDistance = 20.00f;
}


