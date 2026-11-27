#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EWindowCleanerCommand.h"
#include "EWindowCleanerPhase.h"
#include "WindowCleanerMotion.h"
#include "WindowCleaner.generated.h"

class APlayerCharacter;
class UAudioComponent;
class UDialogDataAsset;
class UMaterialInstanceDynamic;
class UPaintableSurfaceComponent;
class USceneComponent;
class USoundBase;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API AWindowCleaner : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPaintableSurfaceComponent* Surface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PaneMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Carriage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* BotPivot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BotMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ArmMeshLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ArmMeshRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BrushMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ColumnCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StampWidthScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotDescendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotAscendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StrokeBottomPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MotionRampSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StopOvershootCm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StopOvershootSettleSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoapShakeCm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoapShakeFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoapStampOffsetCm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CleanStampOffsetCm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoapCatchUpScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotSurfaceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotTiltSmoothing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClientRenderDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ClientSmoothing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BotCelebrateParameterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoldAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoldOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoldInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoldInDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BrushSpinSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BrushSpinUpRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BrushSpinDownRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DirtLookAheadCm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* RailMoveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* SoapSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* WipeSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* CelebrationSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* CelebrationFinishedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* WindowCleanedShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoScalePane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PaneMeshBaseSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDirt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CelebrationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCelebrationStartsAtLastColumn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CelebrationLoops;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CelebrationLoopTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CelebrationLoopBottom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CelebrationSpinSpeed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Motion, meta=(AllowPrivateAccess=true))
    FWindowCleanerMotion Motion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* BotMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* CelebrationAudio;
    
public:
    AWindowCleaner(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetFolded(bool bInFolded);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_Motion();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsViewUpGlassUp(FVector ViewForward, FVector ViewRight, FVector ViewUp) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsViewRightGlassRight(FVector ViewForward, FVector ViewRight, FVector ViewUp) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSoaping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSoapCatchingUp() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRemovingDirt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMovingVertical() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMovingHorizontal() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFolded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFoldActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCleaning() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCelebrating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBusy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBotVisiblyMoving() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleFullyCleaned();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWindowCleanerPhase GetVisiblePhase() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPaintableSurfaceComponent* GetSurface() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetColumnCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetBrushVisualUV() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBrushSpinFraction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetBotVelocity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetArmExtentCm() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetArmExtent() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DebugToggleFastClean();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool Command(EWindowCleanerCommand InCommand, APlayerCharacter* User);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnWindowCleaned();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnSoapingChanged(bool bSoaping);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnSoapCatchingUpChanged(bool bCatchingUp);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnRemovingDirtChanged(bool bRemoving);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnPhaseChanged(EWindowCleanerPhase Phase);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMovingVerticalChanged(bool bMoving, bool bMovingDown);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMovingHorizontalChanged(bool bMoving, bool bMovingRight);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnMovingChanged(bool bMoving);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnCommand(EWindowCleanerCommand InCommand, APlayerCharacter* User);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnCleaningChanged(bool bCleaning);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnCelebrationFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnBotStopped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnBotRunning(FVector WorldVelocity, float Speed, float DeltaSeconds);
    
};

