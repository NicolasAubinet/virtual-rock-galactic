#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MicrowaveSinusoidalChargeWidget.generated.h"

class AMicrowaveWeapon;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class FSD_API UMicrowaveSinusoidalChargeWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ElementCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Bleed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Exponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DriveBoundWidgetOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<float> ElementAlphas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AMicrowaveWeapon> BoundWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidget* element_0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidget* element_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidget* element_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWidget* element_3;
    
public:
    UMicrowaveSinusoidalChargeWidget();

    UFUNCTION(BlueprintCallable)
    void UnbindFromMicrowaveWeapon();
    
    UFUNCTION(BlueprintCallable)
    void SetAlpha(float InAlpha);
    
    UFUNCTION(BlueprintCallable)
    void RefreshElementAlphas();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnElementAlphasUpdated(const TArray<float>& InElementAlphas);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> GetElementAlphas() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElementAlpha(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMicrowaveWeapon* GetBoundMicrowaveWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAlpha() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ComputeElementAlpha(float InAlpha, int32 Index, int32 InElementCount, float InBleed, float InExponent);
    
    UFUNCTION(BlueprintCallable)
    void BindToMicrowaveWeapon(AMicrowaveWeapon* InWeapon);
    
};

