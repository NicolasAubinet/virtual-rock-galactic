#pragma once
#include "CoreMinimal.h"
#include "PerkMaintenanceCharacterRewards.generated.h"

class UItemID;
class UItemSkin;

USTRUCT(BlueprintType)
struct FPerkMaintenanceCharacterRewards {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* TraversalTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemSkin*> Skins;
    
    FSD_API FPerkMaintenanceCharacterRewards();
};

