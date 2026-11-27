#pragma once
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "IRandRange.h"
#include "RejoinListener.h"
#include "Templates/SubclassOf.h"
#include "MissionDrinkItem.generated.h"

class UAnimMontage;
class UAnimationAsset;
class UCapacityHoldingItemAggregator;
class UDialogDataAsset;
class UStatusEffect;

UCLASS(Abstract, Blueprintable)
class FSD_API AMissionDrinkItem : public AAnimatedItem, public IRejoinListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapacityHoldingItemAggregator* Capacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FPDrinkMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* TPDrinkMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* Item_EquipAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* Item_DrinkAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* SaluteShoutOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* ShoutOnEquipEmpty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownAfterDrink;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanDrinkBeforeEquipAnimFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownAfterEquip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FromStartDrinkingTillBuffActiveTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SupplyStatusWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> DrinkBuff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrinkBuffDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* DrinkBuffInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange IntoxicationStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntoxicationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntoxicationRecovery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float CooldownLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimationPlaybackRate;
    
public:
    AMissionDrinkItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerPlayDrinkAnimation();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerOnIntoxicationExpired();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Drink();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnDrinkFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnMatchEnded();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastPlayDrinkAnimation();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void MulticastOnIntoxicationExpired();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CheckCanSalute() const;
    

    // Fix for true pure virtual functions not being implemented
};

