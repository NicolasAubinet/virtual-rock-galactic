#pragma once
#include "CoreMinimal.h"
#include "EDamageComponentType.h"
#include "EDamageUpgrade.h"
#include "EMultiHitscanUpgradeType.h"
#include "StandardItemUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "MultiHitscanUpgrade.generated.h"

class AFSDPlayerState;
class AItem;
class AProjectileBase;

UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UMultiHitscanUpgrade : public UStandardItemUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiHitscanUpgradeType upgradeType;
    
public:
    UMultiHitscanUpgrade();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AItem> Item, AFSDPlayerState* Player, EMultiHitscanUpgradeType NewUpgradeType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetPelletProjectileStaggerChance(TSubclassOf<AItem> Item, TSubclassOf<AProjectileBase> ProjectileClass, AFSDPlayerState* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetPelletProjectileDamage(TSubclassOf<AItem> Item, TSubclassOf<AProjectileBase> ProjectileClass, AFSDPlayerState* Player, EDamageUpgrade NewUpgradeType, EDamageComponentType DamageComponentType);
    
};

