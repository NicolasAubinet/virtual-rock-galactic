#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DismantlerRoundsSettings.h"
#include "AttachedDismantleBullet.generated.h"

class UDamageComponent;
class UMaterialInterface;
class UParticleSystem;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AAttachedDismantleBullet : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* ShrapnelDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachedBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BurstDebrisParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DebrisMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDismantlerRoundsSettings Settings;
    
public:
    AAttachedDismantleBullet(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnShrapnelComplete();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAttachedToPlate(UMaterialInterface* PlateMaterial, UPrimitiveComponent* Plate);
    
};

