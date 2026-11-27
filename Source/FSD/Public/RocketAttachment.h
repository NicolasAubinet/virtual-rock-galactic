#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ERocketAttachmentState.h"
#include "OnRocketAttachmentDelegateDelegate.h"
#include "RocketAttachment.generated.h"

class UCarryingItemUsable;
class UDroneUseComponent;
class USingleUsableComponent;

UCLASS(Blueprintable)
class FSD_API ARocketAttachment : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRocketAttachmentDelegate OnRocketAttachmentStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCarryingItemUsable* AttachUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USingleUsableComponent* BuildUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDroneUseComponent* DroneUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ERocketAttachmentState State;
    
public:
    ARocketAttachment(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetState(ERocketAttachmentState NewState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDroneCanUse(const bool bCanUse);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveFreeAttachment();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnterState(ERocketAttachmentState NewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERocketAttachmentState GetState() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector GetDroneUseLocation() const;
    
};

