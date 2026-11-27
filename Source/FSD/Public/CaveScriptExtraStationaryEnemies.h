#pragma once
#include "CoreMinimal.h"
#include "CaveScriptComponent.h"
#include "IRandRange.h"
#include "CaveScriptExtraStationaryEnemies.generated.h"

class UEnemyDescriptor;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UCaveScriptExtraStationaryEnemies : public UCaveScriptComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemyDescriptor* EnemyDescriptor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange Difficulty;
    
public:
    UCaveScriptExtraStationaryEnemies(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UEnemyDescriptor* GetEnemyDescriptor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIRandRange GetDifficulty() const;
    
};

