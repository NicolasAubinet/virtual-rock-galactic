#include "StatChangeStackedStatusEffectItem.h"

UStatChangeStackedStatusEffectItem::UStatChangeStackedStatusEffectItem() {
    this->Stat = NULL;
    this->StatChange = 0.00f;
    this->AffectedByResistances = false;
    this->MaxStacks = 0;
    this->SkipWhileImmune = false;
}


