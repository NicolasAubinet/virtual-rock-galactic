#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CableStart.generated.h"

class ACable;
class ACableEnd;
class UCableEndPoint;
class UCableUsable;
class UOutlineComponent;
class USimpleObjectInfoComponent;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class FSD_API ACableStart : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOutlineComponent* OutlineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USimpleObjectInfoComponent* ObjectInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCableUsable* CableStartUsable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CableConnected, meta=(AllowPrivateAccess=true))
    bool bCableConnected;
    
public:
    ACableStart(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, NetMulticast, Reliable)
    void RegisterCableEnd(ACableEnd* CableEnd);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveCableConnected();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CableConnected();
    
    UFUNCTION(BlueprintCallable)
    void OnCableConnected(UCableEndPoint* EndPoint, ACable* Cable);
    
};

