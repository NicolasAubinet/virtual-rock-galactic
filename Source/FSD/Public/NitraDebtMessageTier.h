#pragma once
#include "CoreMinimal.h"
#include "NitraDebtMessageTier.generated.h"

USTRUCT(BlueprintType)
struct FNitraDebtMessageTier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DebtAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> Messages;
    
    FSD_API FNitraDebtMessageTier();
};

