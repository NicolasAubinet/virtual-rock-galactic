#pragma once
#include "CoreMinimal.h"
#include "DualWieldWeapon.h"
#include "Templates/SubclassOf.h"
#include "DualMachinePistols.generated.h"

class UDialogDataAsset;
class USceneComponent;
class UStatusEffect;

UCLASS(Blueprintable)
class ADualMachinePistols : public ADualWieldWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> EmptyClipStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> RunAndGunSTE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EmptyClipMaxEnemiesFeared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EmptyClipCourageFleeThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* EmptyClipFearShout;
    
public:
    ADualMachinePistols(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TriggerStatusEffect();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TriggerFearOnNearbyEnemies();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_NotifyClipEmptied();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_ClipEmptied();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEmptyClipFearTriggered(USceneComponent* AttachTo, float Radius, bool IsFirstPerson);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_EmptyClipFearTriggered();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ClipEmptied();
    
};

