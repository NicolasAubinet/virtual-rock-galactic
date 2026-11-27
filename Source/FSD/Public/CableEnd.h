#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CableEnd.generated.h"

class ACable;
class UCableEndPoint;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API ACableEnd : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCableEndPoint* EndPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
public:
    ACableEnd(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRegistered();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveReadyToConnectChanged(const bool bReadyToConnect);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePing(bool InValidPlacement);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveConnected();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnConnected(UCableEndPoint* InEndPoint, ACable* InCable);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCableEndPoint* GetEndPoint() const;
    
};

