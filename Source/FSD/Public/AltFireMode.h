#pragma once
#include "CoreMinimal.h"
#include "AltFireMode.generated.h"

USTRUCT(BlueprintType)
struct FAltFireMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalSpreadMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HorizontalSpreadMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RateOfFireMultiplier;
    
    FSD_API FAltFireMode();
};

