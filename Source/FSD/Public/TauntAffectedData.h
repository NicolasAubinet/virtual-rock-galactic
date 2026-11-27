#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TauntAffectedData.generated.h"

class AActor;
class UStatusEffect;

USTRUCT(BlueprintType)
struct FTauntAffectedData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* EffectCauser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* TauntedActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> Effect;
    
    FSD_API FTauntAffectedData();
};

