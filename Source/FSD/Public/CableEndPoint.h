#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SphereComponent.h"
#include "CableConnectionDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "CableEndPoint.generated.h"

class ACable;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UCableEndPoint : public USphereComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableConnectionDelegate OnConnected;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACable> ConnectType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ConnectedCable, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ACable> ConnectedCable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxConnectRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConnectDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MaxAngles;
    
public:
    UCableEndPoint(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ConnectedCable();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FTransform GetConnectTransform(const FTransform& FromWorldTransform);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Disconnect(ACable* Cable);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Connect(ACable* Cable);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanConnectWith(ACable* Cable, const FTransform& FromWorldTransform);
    
};

