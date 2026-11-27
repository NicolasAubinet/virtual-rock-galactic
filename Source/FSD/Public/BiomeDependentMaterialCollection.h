#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BiomeDependentMaterialCollection.generated.h"

class UBiome;
class UMaterialInterface;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API UBiomeDependentMaterialCollection : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInterface> DefaultMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UBiome>, TSoftObjectPtr<UMaterialInterface>> BiomeOverrides;
    
    UBiomeDependentMaterialCollection();

    UFUNCTION(BlueprintCallable)
    void OverrideMaterial(UStaticMeshComponent* Target, int32 MaterialIndex);
    
};

