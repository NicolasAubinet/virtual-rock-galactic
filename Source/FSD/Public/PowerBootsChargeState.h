#pragma once
#include "CoreMinimal.h"
#include "EPowerBootsChargeChange.h"
#include "PowerBootsChargeState.generated.h"

USTRUCT(BlueprintType)
struct FPowerBootsChargeState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Stage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPowerBootsChargeChange reason;
    
    FSD_API FPowerBootsChargeState();
};

