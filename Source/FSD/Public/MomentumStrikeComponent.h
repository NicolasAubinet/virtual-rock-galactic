#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "MomentumStrikeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMomentumStrikeComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
    UMomentumStrikeComponent(const FObjectInitializer& ObjectInitializer);

};

