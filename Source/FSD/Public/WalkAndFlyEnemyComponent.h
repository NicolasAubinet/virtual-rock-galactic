#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChangedPathfinderStateSigDelegate.h"
#include "StateStats.h"
#include "WalkAndFlyEnemyComponent.generated.h"

class ADeepPathfinderCharacter;
class UDeepPathfinderMovement;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UWalkAndFlyEnemyComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChangedPathfinderStateSig OnChangedPathfinderState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeepPathfinderMovement* CurrentMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnFlyChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_StateChange, meta=(AllowPrivateAccess=true))
    bool IsFlying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkTimeRandomOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool WalkUseTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateStats WalkStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyTimeRandomOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FlyUseTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateStats FlyStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ADeepPathfinderCharacter> OwningPathfinder;
    
public:
    UWalkAndFlyEnemyComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetShouldWalk(bool bShouldWalk, bool bIgnoreMinStateTime);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFlying(bool bIsFlying);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowedToChangeState(const bool bIsAllowed);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_StateChange(const bool bOldIsFlying);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsWalking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsFlying() const;
    
};

