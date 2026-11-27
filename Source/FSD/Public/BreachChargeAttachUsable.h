#pragma once
#include "CoreMinimal.h"
#include "InstantUsable.h"
#include "BreachChargeAttachUsable.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UBreachChargeAttachUsable : public UInstantUsable {
    GENERATED_BODY()
public:
    UBreachChargeAttachUsable(const FObjectInitializer& ObjectInitializer);

};

