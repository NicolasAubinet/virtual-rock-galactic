#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "ExecutionerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExecutionerComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
    UExecutionerComponent(const FObjectInitializer& ObjectInitializer);

};

