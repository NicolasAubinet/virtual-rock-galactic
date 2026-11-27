#include "ManualDetonationUpgrade.h"

UManualDetonationUpgrade::UManualDetonationUpgrade() {
    this->DamagePerStage = 0.00f;
    this->TimeBetweenStages = 0.00f;
    this->RadiusPerStage = 0.00f;
}

void UManualDetonationUpgrade::GetManualDetonationValues(const UManualDetonationUpgrade* Upgrade, float& OutDamagePerStage, float& OutTimeBetweenStages, float& OutRadiusPerStage) {
}


