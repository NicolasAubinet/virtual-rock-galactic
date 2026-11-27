#include "DamageConversionUpgrade.h"
#include "Templates/SubclassOf.h"

UDamageConversionUpgrade::UDamageConversionUpgrade() {
    this->DamageClass = NULL;
    this->ConversionPercentage = 0.50f;
    this->DamageIsAdded = false;
    this->IsPercentage = false;
    this->RequiredClass = NULL;
    this->DamageComponentType = EDamageComponentType::Any;
}

FUpgradeValues UDamageConversionUpgrade::GetUpgradedValue(TSubclassOf<AActor> Item, TSubclassOf<AActor> upgradedItem, AFSDPlayerState* Player, UDamageClass* NewDamageClass) {
    return FUpgradeValues{};
}


