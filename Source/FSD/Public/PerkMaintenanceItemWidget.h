#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PerkMaintenanceWidgetViewModel.h"
#include "Templates/SubclassOf.h"
#include "PerkMaintenanceItemWidget.generated.h"

class UButton;
class UObject;
class UPerkAsset;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPerkMaintenanceItemWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> PerkTooltipWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerkAsset* Perk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMaxed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaintenanceProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerkMaintenanceWidgetViewModel ViewModel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* InspectButton;
    
public:
    UPerkMaintenanceItemWidget();

    UFUNCTION(BlueprintCallable)
    void SetViewModel(const FPerkMaintenanceWidgetViewModel& InViewModel);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void SetPerk(UObject* WorldContext, UPerkAsset* InPerk);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void RefreshFromSavegame(UObject* WorldContext);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_SetViewModel(const FPerkMaintenanceWidgetViewModel& InViewModel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_RefreshedFromSavegame();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_PopulateTooltip(UUserWidget* InTooltipWidget, UPerkAsset* InPerk, int32 Rank);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPerkCompleted();
    
protected:
    UFUNCTION(BlueprintCallable)
    UWidget* GetPerkTooltip();
    
};

