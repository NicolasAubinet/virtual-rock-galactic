#pragma once
#include "CoreMinimal.h"
#include "InstantUsable.h"
#include "Templates/SubclassOf.h"
#include "CarryingItemUsable.generated.h"

class ACarriableItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCarryingItemUsable : public UInstantUsable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACarriableItem> RequiredCarriedItem;
    
    UCarryingItemUsable(const FObjectInitializer& ObjectInitializer);

};

