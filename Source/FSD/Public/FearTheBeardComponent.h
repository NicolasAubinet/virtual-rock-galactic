#pragma once
#include "CoreMinimal.h"
#include "FloatPerkComponent.h"
#include "Templates/SubclassOf.h"
#include "FearTheBeardComponent.generated.h"

class UStatusEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFearTheBeardComponent : public UFloatPerkComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StunRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* SlowEffectInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> SlowEffect;
    
public:
    UFearTheBeardComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivated();
    
    UFUNCTION(BlueprintCallable)
    void FindTargets();
    
};

