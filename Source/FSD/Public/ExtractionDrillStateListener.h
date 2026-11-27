#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EExtractionDrillState.h"
#include "ExtractionDrillStateListener.generated.h"

UINTERFACE(Blueprintable)
class FSD_API UExtractionDrillStateListener : public UInterface {
    GENERATED_BODY()
};

class FSD_API IExtractionDrillStateListener : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDrillStateChanged(EExtractionDrillState NewState);
    
};

