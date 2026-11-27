#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EExtractionDrillState.h"
#include "ExtractionDrillWidget.generated.h"

class USingleUsableComponent;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FSD_API UExtractionDrillWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UExtractionDrillWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillStateChanged(EExtractionDrillState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillButtonUsableChanged(bool CanUse);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDrillButtonChanged(USingleUsableComponent* drillButton, bool CanUse);
    
};

