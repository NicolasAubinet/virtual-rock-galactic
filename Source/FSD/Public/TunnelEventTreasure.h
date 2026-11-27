#pragma once
#include "CoreMinimal.h"
#include "Gem.h"
#include "TunnelEventTreasure.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UTerrainDetectComponent;

UCLASS(Blueprintable)
class FSD_API ATunnelEventTreasure : public AGem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* MeshComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTerrainDetectComponent*> TerrainDetectors;
    
public:
    ATunnelEventTreasure(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PhysicalizeTreasure();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTerrainPointRemoved(USceneComponent* Point);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EnableTerrainDetection();
    
};

