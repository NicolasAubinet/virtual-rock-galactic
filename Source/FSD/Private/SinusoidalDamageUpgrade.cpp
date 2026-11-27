#include "SinusoidalDamageUpgrade.h"
#include "Templates/SubclassOf.h"

USinusoidalDamageUpgrade::USinusoidalDamageUpgrade() {
    this->SinusoidalDamageRangeMin = 0.00f;
    this->SinusoidalDamageRangeMax = 0.00f;
    this->Period = 1.00f;
}

FUpgradeValues USinusoidalDamageUpgrade::GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player) {
    return FUpgradeValues{};
}

FUpgradeValues USinusoidalDamageUpgrade::GetSinusoidalDamageValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player, bool highDamage, bool& hasUpgrade) {
    return FUpgradeValues{};
}


