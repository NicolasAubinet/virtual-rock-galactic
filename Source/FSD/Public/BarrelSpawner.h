#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrelSpawner.generated.h"

UCLASS(Abstract, Blueprintable)
class ABarrelSpawner : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BarrelCount, meta=(AllowPrivateAccess=true))
    int32 BarrelCount;
    
    ABarrelSpawner(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRep_BarrelCount();
    
};

