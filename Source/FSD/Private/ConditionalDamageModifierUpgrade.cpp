#include "ConditionalDamageModifierUpgrade.h"
#include "Templates/SubclassOf.h"

UConditionalDamageModifierUpgrade::UConditionalDamageModifierUpgrade() {
    this->Condition = NULL;
    this->DamageComponentType = EDamageComponentType::Any;
}

FUpgradeValues UConditionalDamageModifierUpgrade::GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player) {
    return FUpgradeValues{};
}


