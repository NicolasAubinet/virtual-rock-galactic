#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoreCorruptionPillar.generated.h"

class UAudioComponent;
class UCurveVector;
class UMeshCarverComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UPointLightComponent;
class USceneComponent;
class USoundCue;
class USplineComponent;
class UStaticMeshComponent;
class UTerrainDetectComponent;
class UTerrainPlacementComponent;

UCLASS(Blueprintable)
class FSD_API ACoreCorruptionPillar : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshCarverComponent* SpaceCarver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshCarverComponent* PillarCarver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshCarverComponent* DestroyPillarCarver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PillarMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* StoneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StoneMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainDetectComponent* TerrainDetector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* Light;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTerrainPlacementComponent* terrainPlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* PillarParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* SpawnEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* PillarDestroyedEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* StoneDestroyedEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* ShieldBeamSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* ShieldBeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldBeamLifeTimeMaxDistanceMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldBeamLifeTimeMinDistanceMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* RockIdleSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* PillarDestroyedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* StoneDestroyedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* DeathRattle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCarvable;
    
    ACoreCorruptionPillar(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnCarvedFree(USceneComponent* Point);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DestroyTrailParticles();
    
    UFUNCTION(BlueprintCallable)
    void DestroyStone();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CarvePillar();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_DestroyPillar();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ActivatePillar();
    
};

