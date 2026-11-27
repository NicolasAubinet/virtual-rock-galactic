#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InkCloud.generated.h"

class UNiagaraComponent;
class USphereComponent;
class UStatusEffectTriggerComponent;

UCLASS(Blueprintable)
class FSD_API AInkCloud : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* CloudCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatusEffectTriggerComponent* StatusTriggerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* CloudEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloudDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutTime;
    
public:
    AInkCloud(const FObjectInitializer& ObjectInitializer);

};

