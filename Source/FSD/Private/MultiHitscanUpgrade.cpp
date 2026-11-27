#include "MultiHitscanUpgrade.h"
#include "Templates/SubclassOf.h"

UMultiHitscanUpgrade::UMultiHitscanUpgrade() {
    this->upgradeType = EMultiHitscanUpgradeType::BulletsPerShot;
}

FUpgradeValues UMultiHitscanUpgrade::GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EMultiHitscanUpgradeType NewUpgradeType) {
    return FUpgradeValues{};
}

FUpgradeValues UMultiHitscanUpgrade::GetPelletProjectileStaggerChance(TSubclassOf<AItem> Item, TSubclassOf<AProjectileBase> ProjectileClass, AFSDPlayerState* Player) {
    return FUpgradeValues{};
}

FUpgradeValues UMultiHitscanUpgrade::GetPelletProjectileDamage(TSubclassOf<AItem> Item, TSubclassOf<AProjectileBase> ProjectileClass, AFSDPlayerState* Player, EDamageUpgrade NewUpgradeType, EDamageComponentType DamageComponentType) {
    return FUpgradeValues{};
}


