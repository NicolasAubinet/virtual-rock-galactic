#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBaseUpgrade.h"
#include "DismantlerRoundsSettings.h"
#include "DismantlerRoundsUpgrade.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDismantlerRoundsUpgrade : public UDamageBonusBaseUpgrade {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDismantlerRoundsSettings Settings;
    
public:
    UDismantlerRoundsUpgrade();

};

