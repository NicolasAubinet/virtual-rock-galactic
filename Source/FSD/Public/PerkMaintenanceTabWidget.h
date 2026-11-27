#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "WindowWidget.h"
#include "PerkMaintenanceTabWidget.generated.h"

class UObject;
class UPerkMaintenanceItemWidget;
class UPerkMaintenanceRewardContainer;
class UVerticalBox;
class UYesNoPromptWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPerkMaintenanceTabWidget : public UWindowWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UYesNoPromptWidget* StarterBonusPopup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerkMaintenanceItemWidget> PerkItemWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PerkGridColumns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UVerticalBox* PerkGridPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPerkMaintenanceItemWidget*> PerkItemWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPerkMaintenanceRewardContainer* RewardContainer;
    
public:
    UPerkMaintenanceTabWidget();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool HasNewNotifications(UObject* WorldContext) const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleStarterBonusPopupClicked(bool bYes);
    
    UFUNCTION(BlueprintCallable)
    void HandlePerkMaintenanceChanged();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void CreatePerkMaintenanceWidgets(UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    bool ClaimReward(UObject* WorldContext);
    
};

