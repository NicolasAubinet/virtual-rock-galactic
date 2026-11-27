#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "BatchSubObjective.generated.h"

class APlayerCharacter;
class AProceduralSetup;
class UDebrisPositioning;

UCLASS(Blueprintable)
class FSD_API ABatchSubObjective : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImportantLocationRadius;
    
public:
    ABatchSubObjective(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TryDebrisPositionPoint(FTransform& outTransform, AProceduralSetup* pls, const FVector& fromLocation, float MinDistance, float desiredDistance, UDebrisPositioning* DebrisPositioning, TSubclassOf<AActor> terrainPlacement, float maxPathLength, bool bIgnoreTerrainPlacement);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsActive() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void CompleteSubObjective(APlayerCharacter* instigatingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnSubObjectiveCompleted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnSubObjectiveActivated();
    
    UFUNCTION(BlueprintCallable)
    void ActivateSubObjective(APlayerCharacter* instigatingPlayer);
    
};

