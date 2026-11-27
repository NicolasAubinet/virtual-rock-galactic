#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "PickKillsComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPickKillsComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
    UPickKillsComponent(const FObjectInitializer& ObjectInitializer);

};

