#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "SinusoidalDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USinusoidalDamageBonus : public UDamageBonusBase {
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
    USinusoidalDamageBonus();

};

