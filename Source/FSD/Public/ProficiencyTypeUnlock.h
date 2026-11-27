#pragma once
#include "CoreMinimal.h"
#include "EProficiency.h"
#include "UnlockReward.h"
#include "ProficiencyTypeUnlock.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UProficiencyTypeUnlock : public UUnlockReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProficiency ProficiencyUnlock;
    
    UProficiencyTypeUnlock();

};

