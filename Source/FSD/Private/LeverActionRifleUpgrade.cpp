#include "LeverActionRifleUpgrade.h"
#include "Templates/SubclassOf.h"

ULeverActionRifleUpgrade::ULeverActionRifleUpgrade() {
    this->upgradeType = ELeverActionRifleUpgrades::AccuracyBonusAfterIdle;
}

FUpgradeValues ULeverActionRifleUpgrade::GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, ELeverActionRifleUpgrades NewUpgradeType) {
    return FUpgradeValues{};
}


