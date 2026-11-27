#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "SceneComponentInterpolatorFinishedDelegateDelegate.h"
#include "SceneComponentInterpolator.generated.h"

class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USceneComponentInterpolator : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneComponentInterpolatorFinishedDelegate OnInterpolationFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TargetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEasingFunc::Type> Easing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Steps;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* ActiveComponent;
    
public:
    USceneComponentInterpolator(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TransformTo(const FTransform& RelativeTransform, float Duration);
    
    UFUNCTION(BlueprintCallable)
    void Stop(bool SnapToTarget);
    
    UFUNCTION(BlueprintCallable)
    void ScaleTo(FVector RelativeScale, float Duration);
    
    UFUNCTION(BlueprintCallable)
    void RotateTo(FRotator RelativeRotation, float Duration);
    
    UFUNCTION(BlueprintCallable)
    void MoveTo(FVector RelativeLocation, float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInterpolating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProgress() const;
    
};

