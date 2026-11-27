#pragma once
#include "CoreMinimal.h"
#include "FSDTremoloSettings.generated.h"

USTRUCT(BlueprintType)
struct FFSDTremoloSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Frequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Depth;
    
    FSD_API FFSDTremoloSettings();
};

