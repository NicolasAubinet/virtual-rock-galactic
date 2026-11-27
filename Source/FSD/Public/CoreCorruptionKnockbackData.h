#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreCorruptionKnockbackData.generated.h"

USTRUCT(BlueprintType)
struct FCoreCorruptionKnockbackData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float force;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Progress;
    
    FSD_API FCoreCorruptionKnockbackData();
};

