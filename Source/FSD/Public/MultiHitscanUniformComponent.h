#pragma once
#include "CoreMinimal.h"
#include "HitDelegateDelegate.h"
#include "HitscanBaseComponent.h"
#include "MultiHitScanHits.h"
#include "MultiHitscanUniformComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UMultiHitscanUniformComponent : public UHitscanBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitDelegate OnHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitDelegate CosmeticOnHit;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConeHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConeLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageMultiplierPerHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowImpactOnHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GeneralImpactAudioVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayImpactSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> DamagedActorCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMultiHitScanHits Hits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsHit;
    
public:
    UMultiHitscanUniformComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit(const FMultiHitScanHits& hitResults);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHalfAngle() const;
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit(const FMultiHitScanHits& hitResults);
    
};

