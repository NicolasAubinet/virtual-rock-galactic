#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "DismantlerRoundsSettings.h"
#include "DismantlerRoundsBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDismantlerRoundsBonus : public UDamageBonusBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDismantlerRoundsSettings Settings;
    
public:
    UDismantlerRoundsBonus();

};

