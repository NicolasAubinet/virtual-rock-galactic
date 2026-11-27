#pragma once
#include "CoreMinimal.h"
#include "DebrisDecalItem.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FDebrisDecalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectionDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    FSD_API FDebrisDecalItem();
};

