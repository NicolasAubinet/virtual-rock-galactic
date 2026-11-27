#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ParticleSystemData.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FParticleSystemData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ParticleRelativeTransform;
    
    FSD_API FParticleSystemData();
};

