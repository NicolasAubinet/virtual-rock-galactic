#include "EnemyRelocationParams.h"

FEnemyRelocationParams::FEnemyRelocationParams() {
    this->bIsRelocatingEnemy = false;
    this->DesiredRelocationCandidates = 0;
    this->MinDistanceToImportantLocations = 0.00f;
    this->MinDistance = 0.00f;
}

