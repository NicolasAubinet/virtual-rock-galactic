#pragma once
#include "CoreMinimal.h"
#include "EChargedWeaponUpgrades.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "ChargedWeaponUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
class UDamageClass;

UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UChargedWeaponUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EChargedWeaponUpgrades upgradeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* BonusDamageClass;
    
public:
    UChargedWeaponUpgrade();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EChargedWeaponUpgrades NewUpgradeType);
    
};

