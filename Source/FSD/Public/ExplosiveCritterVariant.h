#pragma once
#include "CoreMinimal.h"
#include "ExplosiveCritterVariant.generated.h"

class AFSDPawn;

USTRUCT(BlueprintType)
struct FExplosiveCritterVariant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AFSDPawn> ExplosiveVariant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnRateMultiplier;
    
    FSD_API FExplosiveCritterVariant();
};

