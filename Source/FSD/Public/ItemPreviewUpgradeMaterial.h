#pragma once
#include "CoreMinimal.h"
#include "ItemPreviewUpgradeMaterial.generated.h"

class UItemUpgrade;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FItemPreviewUpgradeMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemUpgrade* Upgrade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaterialSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    FSD_API FItemPreviewUpgradeMaterial();
};

