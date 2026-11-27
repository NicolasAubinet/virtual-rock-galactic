#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "StatChangeStackedStatusEffectItem.generated.h"

class UPawnStat;

UCLASS(Blueprintable, EditInlineNew)
class UStatChangeStackedStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* Stat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StatChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AffectedByResistances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SkipWhileImmune;
    
public:
    UStatChangeStackedStatusEffectItem();

};

