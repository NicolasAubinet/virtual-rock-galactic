#pragma once
#include "CoreMinimal.h"
#include "ExplosiveCritterVariant.h"
#include "Mutator.h"
#include "Templates/SubclassOf.h"
#include "ExplosiveSpoilsMutator.generated.h"

class AFSDPawn;
class UBaseCritterDescriptor;
class UDamageComponent;
class UEnemyDescriptor;
class UExplosiveSpoilsEffect;
class UTerrainMaterial;

UCLASS(Blueprintable, EditInlineNew)
class FSD_API UExplosiveSpoilsMutator : public UMutator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AFSDPawn>, FExplosiveCritterVariant> ExplosiveCritterVariants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplosionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExplosionDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UDamageComponent> ExplosionDamageComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UExplosiveSpoilsEffect> ExplosionEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveDiameterCM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveNoiseCM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveBurnThicknessCM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTerrainMaterial> GoldCraterMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoarderClusterBombsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGuaranteeSpawnAtMissionStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UBaseCritterDescriptor> GuaranteedSpawnDescriptor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGuaranteeEncounterSpawnAtMissionStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UEnemyDescriptor> GuaranteedEncounterDescriptor;
    
public:
    UExplosiveSpoilsMutator();

};

