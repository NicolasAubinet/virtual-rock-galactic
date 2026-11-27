#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AttackingPointInterface.h"
#include "DamageData.h"
#include "EPitJawState.h"
#include "EnemyPawn.h"
#include "PitJaw.generated.h"

class AActor;
class AProceduralSetup;
class UGrabberComponent;
class UHealthComponent;
class UHealthComponentBase;
class UMeleeAttackComponent;
class UMeshCarverComponent;
class UResourceData;
class USkeletalMeshComponent;

UCLASS(Abstract, Blueprintable)
class FSD_API APitJaw : public AEnemyPawn, public IAttackingPointInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGrabberComponent* GrabberComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeleeAttackComponent* FirstBite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeleeAttackComponent* Bite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshCarverComponent* MouthCarve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshCarverComponent* MinorCarve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshCarverComponent* MajorCarve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LungeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BitesPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostRelocateGracePeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LockOnDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoseLockOnDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DownDetectDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpDetectDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabOffsetZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageThresholdProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseQuickEscape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EscapeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float QuickEscapeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelocateDelayMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelocateDelayMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelocateMinDistSquared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelocateMaxDistSquared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float RelocateDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FTransform> RelocationPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDidMouthCarve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDidMinorCarve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDidMajorCarve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StateTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EPitJawState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthTarget;
    
public:
    APitJaw(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    bool TryGetSafestRelocationPoint(FTransform& outSafestRelocationPoint);
    
    UFUNCTION(BlueprintCallable)
    void SpawnResourceChunk(UResourceData* Data, float Size, float DistanceFromMouth);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    
    UFUNCTION(BlueprintCallable)
    void OnRelocationComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnPostAmbush();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEscapeComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnDugOut();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnDied(UHealthComponentBase* HealthComponent);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPitJawState GetState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetMouthLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetMouthDirection() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetCurrentTarget();
    
protected:
    UFUNCTION(BlueprintCallable)
    void FindRelocationPoints(AProceduralSetup* pls, int32 desiredCandidates);
    
    UFUNCTION(BlueprintCallable)
    void DoMouthCarve();
    
    UFUNCTION(BlueprintCallable)
    void DoMinorCarve();
    
    UFUNCTION(BlueprintCallable)
    void DoMajorCarve();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnStateChanged(EPitJawState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMouthCarve();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMinorCarve();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMajorCarve();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_FinishRelocation(FTransform relocationPoint);
    

    // Fix for true pure virtual functions not being implemented
};

