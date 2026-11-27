#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "ECarveFilterType.h"
#include "StaticMeshCarverComponent.generated.h"

class UStaticMeshCarver;
class UTerrainMaterial;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UStaticMeshCarverComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMeshCarver* StaticMeshCarver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* TerrainMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECarveFilterType Filter;
    
    UStaticMeshCarverComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Carve();
    
};

