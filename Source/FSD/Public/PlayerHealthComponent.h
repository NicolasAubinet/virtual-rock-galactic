#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AudioWithCooldown.h"
#include "FullHealthSignatureDelegate.h"
#include "HealthComponent.h"
#include "HealthRegeneratingChangedDelegate.h"
#include "HealthRegenerationParams.h"
#include "HitSigDelegate.h"
#include "RejoinListener.h"
#include "ShieldGainedFromKillDelegate.h"
#include "Templates/SubclassOf.h"
#include "PlayerHealthComponent.generated.h"

class AActor;
class AController;
class APlayerCharacter;
class UCurveFloat;
class UParticleSystem;
class UParticleSystemComponent;
class UPlayerDamageTakenMutator;
class USharedHealthMutator;
class USoundBase;
class USoundMix;
class UStatusEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerHealthComponent : public UHealthComponent, public IRejoinListener {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullHealthSignature OnFullHealthCannotHeal;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullHealthSignature OnHealedFromCrystalEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealthRegeneratingChanged OnHealthRegeneratingChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShieldGainedFromKill OnShieldGainedFromSmallKill;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShieldGainedFromKill OnShieldGainedFromLargeKill;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitSig OnPlayerHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondChanceDamageCap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaxHealth, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaxArmor, meta=(AllowPrivateAccess=true))
    float MaxArmor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ArmorDamage, meta=(AllowPrivateAccess=true))
    float ArmorDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReviveHealthReturnRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReviveArmorReturnRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthPerCrystalVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealthRegenerationParams HealthRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ArmorRegenCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldRegenDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* GenericImpactParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ShieldLinkEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioWithCooldown AudioFriendlyFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* AudioShieldGainedFromSmallKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* AudioShieldGainedFromLargeKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundMix* ShieldGainedFromKillSoundMix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ShieldLinkInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InvulnerabilityDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReviveInvulnerabilityTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPlayerDamageTakenMutator* DamageTakenMutator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> IronWillStatusEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* IronWillStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IronWillActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IronWillTimeToActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> SecondChanceStatusEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* SecondChanceStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float SecondChanceDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool SecondChanceActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USharedHealthMutator* SharedHealthMutator;
    
public:
    UPlayerHealthComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    UStatusEffect* SetSecondChanceStatusEffect(TSubclassOf<UStatusEffect> steClass);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    UStatusEffect* SetIronWillStatusEffect(TSubclassOf<UStatusEffect> steClass);
    
    UFUNCTION(BlueprintCallable)
    void SetInvulnerable(float Duration);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TryActivateSecondChance();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TryActivateIronWill();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_MaxHealth();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MaxArmor();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ArmorDamage(float oldDamage);
    
    UFUNCTION(BlueprintCallable)
    void OnEnemyKilled(const FGameplayTagContainer& enemyTags, AActor* killedEnemy);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLowHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSecondChanceTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSecondChanceDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSecondChanceActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingIronWillActivationTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsHealthRegenerating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIronWillActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthRegeneratingTargetRatio() const;
    
protected:
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void Client_ShieldGainedFromKill(float amount, bool isLargeEnemy);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetHealthRegenerating(bool isRegenerating);
    
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void Client_OnFriendlyFire(AController* EventInstigator, AActor* DamageCauser);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_HealthFullCannotHeal();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanActivateSecondChance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanActivateIronWill() const;
    

    // Fix for true pure virtual functions not being implemented
};

