#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EInputKeys.h"
#include "MonitoringStationAlarmBorder.h"
#include "MonitoringStationAlarmVector.h"
#include "Templates/SubclassOf.h"
#include "MonitoringStation_S07.generated.h"

class ADepressurerizationButton;
class ANiagaraActor;
class APlayerCharacter;
class AWindowCleaner;
class UBorder;
class UBoxComponent;
class UDialogDataAsset;
class UInstantUsable;
class UMaterialInstanceDynamic;
class UPointLightComponent;
class USceneComponent;
class UTextBlock;

UCLASS(Blueprintable)
class FSD_API AMonitoringStation_S07 : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AlarmWidgetTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AlarmImageNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AlarmTextNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMonitoringStationAlarmBorder> AlarmBorders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> ScreenMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTextBlock*> ScreenTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UBorder*> ScreenBorders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* MonitorShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MonitorShoutChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MonitorShoutCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MonitorShoutDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* TooManyTapsShout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TooManyTapsThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TooManyTapsChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TooManyTapsCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* CachedMonitorUser;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* AlarmLight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* MonitorBox1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* MonitorBox2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* MonitorBox3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* MonitorUsable1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* MonitorUsable2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstantUsable* MonitorUsable3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADepressurerizationButton> ButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ButtonPlaceholderTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ANiagaraActor*> VentEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> VentLids;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator VentLidOpenRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentLidOpenDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentLidCloseDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VentLidOvershoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AWindowCleaner*> FoldOnVent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADepressurerizationButton* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> ScreenTextOriginalColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> ScreenBorderOriginalColors;
    
public:
    AMonitoringStation_S07(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopScreenAlarm(float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void StartScreenAlarm(const TArray<FMonitoringStationAlarmVector>& Parameters, float CyclesPerSecond, float MinLightIntensity, float MaxLightIntensity);
    
    UFUNCTION(BlueprintCallable)
    void SetScreenVector(FName ParameterName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    void RegisterAlarmMaterials();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMonitorUsed(APlayerCharacter* User, EInputKeys Key);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsScreenAlarmActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ADepressurerizationButton* GetButton() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAlarmPulse() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnButtonVentStopped(ADepressurerizationButton* InButton);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnButtonVentStarted(ADepressurerizationButton* InButton);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnButtonLidOpened(ADepressurerizationButton* InButton);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnButtonLidClosed(ADepressurerizationButton* InButton);
    
};

