#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "AmmoDrivenWeapon.h"
#include "Templates/SubclassOf.h"
#include "AssaultRifle.generated.h"

class AActor;
class UFSDPhysicalMaterial;
class UStatusEffect;

UCLASS(Blueprintable)
class AAssaultRifle : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FinalShotBonusDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float KillsResetAccuracyDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool KillsTriggersStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> KillTriggeredStatusEffect;
    
public:
    AAssaultRifle(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetFinalShotBonusActive(bool Active);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBonusShotReady();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBonusShotLost();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveBonusShotFired();
    
    UFUNCTION(BlueprintCallable)
    void OnTimerElapsed();
    
    UFUNCTION(BlueprintCallable)
    void OnShotHit(const FHitResult& Hit, bool alwaysPenetrate);
    
    UFUNCTION(BlueprintCallable)
    void OnShotComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnEnemyKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFinalShotBonusActive() const;
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_ResetAccuracy();
    
};

