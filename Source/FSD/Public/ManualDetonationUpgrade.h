#pragma once
#include "CoreMinimal.h"
#include "ItemUpgrade.h"
#include "ManualDetonationUpgrade.generated.h"

class UManualDetonationUpgrade;

UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UManualDetonationUpgrade : public UItemUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamagePerStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBetweenStages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadiusPerStage;
    
public:
    UManualDetonationUpgrade();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetManualDetonationValues(const UManualDetonationUpgrade* Upgrade, float& OutDamagePerStage, float& OutTimeBetweenStages, float& OutRadiusPerStage);
    
};

