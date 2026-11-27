#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "NitraDebtMessageTier.h"
#include "ManagementsFavoriteComponent.generated.h"

class UDialogDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UManagementsFavoriteComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* ShoutMissionControlResponse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNitraDebtMessageTier> NitraDebtMessageTiers;
    
public:
    UManagementsFavoriteComponent(const FObjectInitializer& ObjectInitializer);

};

