#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EPowerBootsChargeChange.h"
#include "PowerBootsChargeWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UPowerBootsChargeWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrainSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeInSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IdleOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxShakeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShakeFrequency;
    
public:
    UPowerBootsChargeWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateOvercharge(float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateCharge(float Progress);
    
    UFUNCTION(BlueprintCallable)
    void SetShakeProgress(float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStageReached(int32 Stage);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargeEnded(EPowerBootsChargeChange reason);
    
};

