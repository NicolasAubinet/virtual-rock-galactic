#pragma once
#include "CoreMinimal.h"
#include "EWindowCleanerPhase.h"
#include "WindowCleanerMotion.generated.h"

USTRUCT(BlueprintType)
struct FWindowCleanerMotion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Column;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetColumn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindowCleanerPhase Phase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartServerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedMultiplier;
    
    FSD_API FWindowCleanerMotion();
};

