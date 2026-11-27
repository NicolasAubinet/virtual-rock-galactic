#include "SupercellPayloadUpgrade.h"

USupercellPayloadUpgrade::USupercellPayloadUpgrade() {
    this->FieldDuration = 6.00f;
    this->FieldRadiusScale = 1.00f;
    this->RadialDamageMultiplier = 0.20f;
    this->IncendiaryHeatDamageRatio = 0.50f;
    this->HeatDamageMultiplier = 1.00f;
    this->RandomBonusDamageMultiplier = 1.00f;
}

float USupercellPayloadUpgrade::GetRadialDamageMultiplier(const USupercellPayloadUpgrade* Upgrade) {
    return 0.0f;
}


