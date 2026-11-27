#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PerkMaintenanceSkinProgressSegmentWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPerkMaintenanceSkinProgressSegmentWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPerkMaintenanceSkinProgressSegmentWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLit(bool bIsLit);
    
};

