#include "CaveScriptExtraStationaryEnemies.h"

UCaveScriptExtraStationaryEnemies::UCaveScriptExtraStationaryEnemies(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EnemyDescriptor = NULL;
}

UEnemyDescriptor* UCaveScriptExtraStationaryEnemies::GetEnemyDescriptor() const {
    return NULL;
}

FIRandRange UCaveScriptExtraStationaryEnemies::GetDifficulty() const {
    return FIRandRange{};
}


