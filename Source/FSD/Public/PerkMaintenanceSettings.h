#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PerkMaintenanceCharacterRewards.h"
#include "Templates/SubclassOf.h"
#include "PerkMaintenanceSettings.generated.h"

class UYesNoPromptWidget;

UCLASS(Blueprintable)
class UPerkMaintenanceSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPerkMaintenanceCharacterRewards> CharacterRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PerksPerReward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StarterBonusPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UYesNoPromptWidget> StarterBonusPopupClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StarterBonusPopupTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StarterBonusPopupMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPerkXP;
    
    UPerkMaintenanceSettings();

};

