#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameEvent.h"
#include "TunnelEventEnemySpawner.generated.h"

class AActor;
class ATunnelEventBase;
class UCurveFloat;
class UDebrisPositioning;
class UEnemyDescriptor;
class UPrimitiveComponent;
class USpawnActorWithDebrisPosComponent;
class USphereComponent;

UCLASS(Blueprintable)
class FSD_API ATunnelEventEnemySpawner : public AGameEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SpawnSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpawnActorWithDebrisPosComponent* SpawnComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ATunnelEventBase>> TunnelTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* TunnelPlacementPositioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TunnelPlacementCostCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* EnemyPlacementPositioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* EnemyPlacementCostCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UEnemyDescriptor> EnemyDescriptor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerCoefficient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ATunnelEventBase> SelectedTunnelClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATunnelEventBase* SpawnedtunnelInstance;
    
public:
    ATunnelEventEnemySpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool TrySpawnEnemy();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartTunnelSpawning();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSpawnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

