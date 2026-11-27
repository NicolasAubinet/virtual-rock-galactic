#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "MultiHitscanHit.h"
#include "MultiHitScanHits.generated.h"

class UFSDPhysicalMaterial;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FMultiHitScanHits {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMultiHitscanHit> Hits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> Components;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UFSDPhysicalMaterial*> PhysicalMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVector_NetQuantize> SpawnLocations;
    
    FSD_API FMultiHitScanHits();
};

