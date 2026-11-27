#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EBarrelFlowExecution.h"
#include "EComboFlow.h"
#include "EFlowFromDirection.h"
#include "EPlayerFlowExecution.h"
#include "HoopsGame.generated.h"

class ABarrelSpawner;
class AFSDPlayerController;
class APhysicsBarrel;
class APlayerCharacter;
class UHoopScoreWidget;
class UParticleSystem;
class USceneComponent;
class UUIHoopHistory;

UCLASS(Abstract, Blueprintable)
class AHoopsGame : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsMovingRightServer, meta=(AllowPrivateAccess=true))
    bool bIsMovingRightServer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMovingRightLocal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentScore, meta=(AllowPrivateAccess=true))
    int32 CurrentScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Cycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CycleLastScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ComboMultiplier, meta=(AllowPrivateAccess=true))
    int32 ComboMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComboMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RedBarrelScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlueBarrelScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BarrelComboCountAchievement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComboInitial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Scores, meta=(AllowPrivateAccess=true))
    TArray<int32> Scores;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float NextFlipTimeServer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NextFlipTimeLocal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToNextRandomScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandomStream RandomSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ABarrelSpawner* BP_BarrelSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorCombo1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorCombo2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorCombo3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUIHoopHistory* HoopHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Hoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerCharacter* LastActivePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHoopScoreWidget* ScoreWidget;
    
public:
    AHoopsGame(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateScoreAchievementProgress();
    
    UFUNCTION(BlueprintCallable)
    void Update(float DeltaTime, EComboFlow& outFLow);
    
    UFUNCTION(BlueprintCallable)
    void StoreScore(int32 newScore);
    
    UFUNCTION(BlueprintCallable)
    void Restart();
    
    UFUNCTION(BlueprintCallable)
    void OnSpaceballInHoop(int32 scoreToAdd);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Scores();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsMovingRightServer();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentScore();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ComboMultiplier();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerInHoop(APlayerCharacter* Player, UParticleSystem* deathEffect, bool& outIsDrunk, EPlayerFlowExecution& outFLow, APlayerCharacter*& outPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnBarrelInHoop(APhysicsBarrel* Barrel, EBarrelFlowExecution& outFLow, float& outBarrelCombo, AFSDPlayerController*& outPlayerController);
    
    UFUNCTION(BlueprintCallable)
    void OnBarglassInHoop(AActor* glass, AFSDPlayerController*& outPlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MoveDirectionChanged();
    
    UFUNCTION(BlueprintCallable)
    void Init();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    int32 GetBarrelScoreData(APhysicsBarrel* Barrel, APhysicsBarrel*& OutBarrel);
    
    UFUNCTION(BlueprintCallable)
    void DataCellInHoop();
    
    UFUNCTION(BlueprintCallable)
    void CollisionDirection(USceneComponent* Box, AActor* Target, EFlowFromDirection& outFLow, AActor*& outTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FVector CalculateMovementVector(float nextFlipTime, float DeltaTime, bool bIsMovingRight);
    
};

