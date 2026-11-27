#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "PerkMaintenanceSkinProgressWidget.generated.h"

class UHorizontalBox;
class UPerkMaintenanceSkinProgressSegmentWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPerkMaintenanceSkinProgressWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerkMaintenanceSkinProgressSegmentWidget> SegmentWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* SegmentPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPerkMaintenanceSkinProgressSegmentWidget*> SegmentWidgets;
    
public:
    UPerkMaintenanceSkinProgressWidget();

    UFUNCTION(BlueprintCallable)
    void Refresh();
    
};

