#pragma once
#include "CoreMinimal.h"
#include "HitNonOverhealDelegateDelegate.h"
#include "HitNothingDelegateDelegate.h"
#include "HitscanBaseComponent.h"
#include "OverhealEffectDelegateDelegate.h"
#include "ReflectiveHitscanHit.h"
#include "ReflectionHitscanComponent.generated.h"

class UTerrainType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UReflectionHitscanComponent : public UHitscanBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverhealEffectDelegate OnOverhealEffect;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitNothingDelegate OnNonPlayerTurretHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitNonOverhealDelegate OnNonOverhealHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverhealEffectDelegate OnPlayerHealHit;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainType* PlatformTerrainType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayImpactSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowImpactOnReflections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDamageOnReflections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StraightenReflectionFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReflectionCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickyFriendlyBeamRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickyTurretBeamRadius;
    
public:
    UReflectionHitscanComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit_Reflection(const FReflectiveHitscanHit& Hit);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RegisterHit(const FReflectiveHitscanHit& Hit);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowHit(const FReflectiveHitscanHit& Hit);
    
};

