#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "PerkMaintenanceRewardContainer.generated.h"

class UObject;
class UPanelWidget;
class UPerkMaintenanceRewardWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPerkMaintenanceRewardContainer : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerkMaintenanceRewardWidget> RewardWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* RewardPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPerkMaintenanceRewardWidget*> RewardWidgets;
    
public:
    UPerkMaintenanceRewardContainer();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void RefreshRewardWidgets(UObject* WorldContext);
    
};

