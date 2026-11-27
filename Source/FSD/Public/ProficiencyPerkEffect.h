#pragma once
#include "CoreMinimal.h"
#include "ProficiencyPerkEffect.generated.h"

class UFloatPerkActivation;

USTRUCT(BlueprintType)
struct FProficiencyPerkEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatPerkActivation* PerkActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText FormattedDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    FSD_API FProficiencyPerkEffect();
};

