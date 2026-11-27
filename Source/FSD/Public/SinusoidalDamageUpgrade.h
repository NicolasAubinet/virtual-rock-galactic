#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBaseUpgrade.h"
#include "Templates/SubclassOf.h"
#include "UpgradeValues.h"
#include "SinusoidalDamageUpgrade.generated.h"

class AActor;
class AFSDPlayerState;

UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class USinusoidalDamageUpgrade : public UDamageBonusBaseUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SinusoidalDamageRangeMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SinusoidalDamageRangeMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Period;
    
public:
    USinusoidalDamageUpgrade();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetUpgradedValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FUpgradeValues GetSinusoidalDamageValue(TSubclassOf<AActor> Item, AFSDPlayerState* Player, bool highDamage, bool& hasUpgrade);
    
};

