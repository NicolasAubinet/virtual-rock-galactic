#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PerkMaintenanceRewardViewModel.h"
#include "Templates/SubclassOf.h"
#include "PerkMaintenanceRewardWidget.generated.h"

class UButton;
class UItemID;
class UItemSkin;
class UObject;
class UPlayerCharacterID;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class UPerkMaintenanceRewardWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> SkinTooltipWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* PreviewButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* UnlockButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TrackIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerkMaintenanceRewardViewModel ViewModel;
    
public:
    UPerkMaintenanceRewardWidget();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void SetTrack(UObject* WorldContext, int32 InTrackIndex);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_SetViewModel(const FPerkMaintenanceRewardViewModel& InViewModel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_PopulateTooltip(UUserWidget* InTooltipWidget, UItemSkin* InSkin, UItemID* InTraversalTool, UPlayerCharacterID* InCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRewardUnlocked(UItemSkin* UnlockedSkin);
    
    UFUNCTION(BlueprintCallable)
    void HandleUnlockButtonClicked();
    
    UFUNCTION(BlueprintCallable)
    UWidget* GetSkinTooltip();
    
};

