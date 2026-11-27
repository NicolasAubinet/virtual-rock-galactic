#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "EnemyRarityMutator.generated.h"

class UEnemyDescriptor;

UCLASS(Blueprintable, EditInlineNew)
class FSD_API UEnemyRarityMutator : public UMutator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RarityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnAmountMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DifficultyMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* EnemyDescriptor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AddToEnemyPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PoolWeightMultiplier;
    
    UEnemyRarityMutator();

};

