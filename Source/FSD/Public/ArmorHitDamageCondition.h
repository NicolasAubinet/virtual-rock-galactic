#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "ArmorHitDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UArmorHitDamageCondition : public UDamageCondition {
    GENERATED_BODY()
public:
    UArmorHitDamageCondition();

};

