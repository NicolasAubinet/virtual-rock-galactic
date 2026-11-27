#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "GrenadeLauncher.generated.h"

UCLASS(Blueprintable)
class AGrenadeLauncher : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepUsingWhileSprinting;
    
public:
    AGrenadeLauncher(const FObjectInitializer& ObjectInitializer);

};

