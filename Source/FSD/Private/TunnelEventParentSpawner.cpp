#include "TunnelEventParentSpawner.h"

UTunnelEventParentSpawner::UTunnelEventParentSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MinToSpawn = 0;
    this->MaxToSpawn = 0;
    this->bExclusiveSpawn = false;
}


