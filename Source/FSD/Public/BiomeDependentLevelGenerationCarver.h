#pragma once
#include "CoreMinimal.h"
#include "LevelGenerationCarverComponent.h"
#include "BiomeDependentLevelGenerationCarver.generated.h"

class UBiomeDependentCarverCollection;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBiomeDependentLevelGenerationCarver : public ULevelGenerationCarverComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UBiomeDependentCarverCollection> SoftTerrainCollection;
    
public:
    UBiomeDependentLevelGenerationCarver(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnCollectionLoadComplete();
    
};

