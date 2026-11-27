#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BiomeDependentCarverCollection.generated.h"

class UBiome;
class UObject;
class UTerrainMaterial;

UCLASS(Blueprintable)
class FSD_API UBiomeDependentCarverCollection : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTerrainMaterial> DefaultMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UBiome>, TSoftObjectPtr<UTerrainMaterial>> BiomeOverrides;
    
    UBiomeDependentCarverCollection();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    UTerrainMaterial* K2_GetMaterial(UObject* WorldContext);
    
};

