#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoscoIgnoreComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UBoscoIgnoreComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UBoscoIgnoreComponent(const FObjectInitializer& ObjectInitializer);

};

