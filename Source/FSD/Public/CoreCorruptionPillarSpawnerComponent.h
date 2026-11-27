#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "PillarSpawnerDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "CoreCorruptionPillarSpawnerComponent.generated.h"

class ACoreCorruptionPillar;
class UDebrisPositioning;
class UDifficultySetting;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UCoreCorruptionPillarSpawnerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPillarSpawnerDelegate OnPillarSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnFinishedSpawningPillars;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Spawned, meta=(AllowPrivateAccess=true))
    ACoreCorruptionPillar* spawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UDifficultySetting*, int32> AmountByDifficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACoreCorruptionPillar> PillarClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDeviation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialSpawnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AmountToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnOneAtATime;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisallowSpawning;
    
    UCoreCorruptionPillarSpawnerComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopSpawning();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StartSpawning();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SpawnPillar();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PreFetchSpawnLocations(const FVector& Origin);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Spawned();
    
    UFUNCTION(BlueprintCallable)
    void OnPillarDestroyed(ACoreCorruptionPillar* Pillar);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACoreCorruptionPillar* GetPillar() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool CollectSpawnLocations(const FVector& Origin, TArray<FTransform> fallbackTransforms);
    
};

