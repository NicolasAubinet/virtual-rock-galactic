#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "CoreCorruptionRift.generated.h"

class ACoreCorruptionCrystal;
class UInstancedStaticMeshComponent;
class USceneComponent;
class USpawnActorWithDebrisPosComponent;
class USplineComponent;
class UTerrainPlacementComponent;

UCLASS(Blueprintable)
class FSD_API ACoreCorruptionRift : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* InstancedSpikesRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UInstancedStaticMeshComponent*> SpikeMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SpikeLocationSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpawnActorWithDebrisPosComponent* DebrisSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CrystalSpawnPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CrystalDeathPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SpikeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BonesToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Seed, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACoreCorruptionCrystal> CrystalClass;
    
public:
    ACoreCorruptionRift(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SpawnSpikes();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_MakeDormant();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Seed();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<FTransform> GetFallbackPillarTransforms();
    
};

