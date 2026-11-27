#pragma once
#include "CoreMinimal.h"
#include "PerkLogic.h"
#include "PressurePerformerShoutLogic.generated.h"

class UDialogDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPressurePerformerShoutLogic : public UPerkLogic {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* ShoutTeammateDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* ShoutLastStanding;
    
public:
    UPressurePerformerShoutLogic(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnAnyDwarfDied();
    
};

