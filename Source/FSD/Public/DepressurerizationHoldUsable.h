#pragma once
#include "CoreMinimal.h"
#include "SingleUsableComponent.h"
#include "DepressurerizationHoldUsable.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UDepressurerizationHoldUsable : public USingleUsableComponent {
    GENERATED_BODY()
public:
    UDepressurerizationHoldUsable(const FObjectInitializer& ObjectInitializer);

};

