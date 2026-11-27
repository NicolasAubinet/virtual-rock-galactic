#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TauntAffectedData.h"
#include "TauntAffectedComponent.generated.h"

class AActor;
class UStatusEffect;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UTauntAffectedComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTauntAffectedData EffectData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStatusEffect* TauntedEffect;
    
public:
    UTauntAffectedComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    AActor* GetEffectCauser() const;
    
};

