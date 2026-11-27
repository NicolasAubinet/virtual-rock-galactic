#pragma once
#include "CoreMinimal.h"
#include "FSDActiveEventResponse.generated.h"

USTRUCT(BlueprintType)
struct FFSDActiveEventResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString End_At;
    
    FSD_API FFSDActiveEventResponse();
};

