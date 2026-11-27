#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "TraversalSkinUnlock.generated.h"

class UItemID;
class UItemSkin;

UCLASS(Blueprintable, EditInlineNew)
class UTraversalSkinUnlock : public UUnlockReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UItemID*, UItemSkin*> ItemSkinMap;
    
    UTraversalSkinUnlock();

};

