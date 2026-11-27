#pragma once
#include "CoreMinimal.h"
#include "VanityItemRewarder.h"
#include "TattooVanityItemRewarder.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTattooVanityItemRewarder : public UVanityItemRewarder {
    GENERATED_BODY()
public:
    UTattooVanityItemRewarder(const FObjectInitializer& ObjectInitializer);

};

