#include "ChargedWeaponUpgrade.h"
#include "Templates/SubclassOf.h"

UChargedWeaponUpgrade::UChargedWeaponUpgrade() {
    this->upgradeType = EChargedWeaponUpgrades::ShotCostAtFullCharge;
    this->BonusDamageClass = NULL;
}

FUpgradeValues UChargedWeaponUpgrade::GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EChargedWeaponUpgrades NewUpgradeType) {
    return FUpgradeValues{};
}


