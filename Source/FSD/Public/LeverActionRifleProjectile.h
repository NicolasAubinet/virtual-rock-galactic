#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DecalData.h"
#include "EImpactDecalSize.h"
#include "Projectile.h"
#include "LeverActionRifleProjectile.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class UTerrainMaterial;

UCLASS(Abstract, Blueprintable)
class ALeverActionRifleProjectile : public AProjectile {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnDecalOnImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EImpactDecalSize ImpactDecalSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDecalData ImpactDecalOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CarveTerrainOnImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveDiameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveNoise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveBurnThickness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveNormalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveNormalSqueeze;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CarveUsesBulletBurntMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* CarveBurntMaterialOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CarveDissolvesPlatforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpawnCarveParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarveDebrisSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayCarveCrumbleSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* TrailEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator TrailRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SuppressMeshOffsetBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* TrailComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueDriveDuration;
    
public:
    ALeverActionRifleProjectile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopTrail();
    
    UFUNCTION(BlueprintCallable)
    void StartValueDrive();
    
    UFUNCTION(BlueprintCallable)
    void StartTrail();
    
    UFUNCTION(BlueprintCallable)
    void SetTrailRotationOffset(FRotator Offset);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnValueDriveUpdated(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetTrailRotation() const;
    
};

