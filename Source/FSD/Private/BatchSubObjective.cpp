#include "BatchSubObjective.h"
#include "Templates/SubclassOf.h"

ABatchSubObjective::ABatchSubObjective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ImportantLocationRadius = 0.00f;
}

bool ABatchSubObjective::TryDebrisPositionPoint(FTransform& outTransform, AProceduralSetup* pls, const FVector& fromLocation, float MinDistance, float desiredDistance, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, float maxPathLength, bool bIgnoreTerrainPlacement) {
    return false;
}

bool ABatchSubObjective::GetIsActive() const {
    return false;
}

void ABatchSubObjective::CompleteSubObjective(APlayerCharacter* instigatingPlayer) {
}



void ABatchSubObjective::ActivateSubObjective(APlayerCharacter* instigatingPlayer) {
}


