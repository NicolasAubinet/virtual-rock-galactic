#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyRelocationParams.generated.h"

USTRUCT(BlueprintType)
struct FEnemyRelocationParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRelocatingEnemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DesiredRelocationCandidates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistanceToImportantLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatRange MaxDistanceRange;
    
    FSD_API FEnemyRelocationParams();
};

