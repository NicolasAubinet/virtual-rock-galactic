#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/NetSerialization.h"
#include "Templates/SubclassOf.h"
#include "ExplosiveCritterComponent.generated.h"

class AProjectileBase;
class UExplosiveSpoilsEffect;
class UExplosiveSpoilsMutator;
class UMaterialInstance;
class UTerrainMaterial;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExplosiveCritterComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UExplosiveSpoilsMutator* SourceMutator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGoldCrater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumClusterBombs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AProjectileBase> ClusterProjectileClass;
    
public:
    UExplosiveCritterComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerExplosion();
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayExplosionEffect(TSubclassOf<UExplosiveSpoilsEffect> EffectClass, FVector_NetQuantize Location, UMaterialInstance* DebrisMaterial, UTerrainMaterial* RockMaterial);
    
};

