#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EPowerBootsChargeChange.h"
#include "PowerBootsChargeEffect.generated.h"

class APlayerCharacter;

UCLASS(Abstract, Blueprintable)
class UPowerBootsChargeEffect : public UObject {
    GENERATED_BODY()
public:
    UPowerBootsChargeEffect();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargeStageChanged(APlayerCharacter* Character, int32 NewStage, int32 OldStage, EPowerBootsChargeChange reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBootsRemoved(APlayerCharacter* Character);
    
};

