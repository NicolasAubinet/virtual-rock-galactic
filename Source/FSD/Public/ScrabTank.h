#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EScrabTankSlot.h"
#include "ScrabTank.generated.h"

class USceneComponent;
class USplineComponent;

UCLASS(Blueprintable)
class FSD_API AScrabTank : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* PathSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* BeetleMount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* BeetleVisual;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveSpeedUUPerSec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EaseExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bYawOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FacingYawOffsetDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VisualRotInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EScrabTankSlot InitialSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterNormalized;
    
public:
    AScrabTank(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TabRight();
    
    UFUNCTION(BlueprintCallable)
    void TabLeft();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetBeetleMount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetBeetleAttach() const;
    
    UFUNCTION(BlueprintCallable)
    void Feed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnScream();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMoveStarted(EScrabTankSlot from, EScrabTankSlot to);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnArrived(EScrabTankSlot ArrivedAt);
    
};

