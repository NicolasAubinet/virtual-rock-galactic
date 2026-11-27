#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "SupercellPayloadUpgrade.generated.h"

class USupercellPayloadUpgrade;

UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class USupercellPayloadUpgrade : public UItemUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FieldDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FieldRadiusScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadialDamageMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IncendiaryHeatDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeatDamageMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomBonusDamageMultiplier;
    
public:
    USupercellPayloadUpgrade();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetRadialDamageMultiplier(const USupercellPayloadUpgrade* Upgrade);
    
};

