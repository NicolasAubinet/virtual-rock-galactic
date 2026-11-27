#pragma once
#include "CoreMinimal.h"
#include "LevelGenerationCarverComponent.h"
#include "RandomLevelGenerationCarverComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URandomLevelGenerationCarverComponent : public ULevelGenerationCarverComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveChance;
    
    URandomLevelGenerationCarverComponent(const FObjectInitializer& ObjectInitializer);

};

