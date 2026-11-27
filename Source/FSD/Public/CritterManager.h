#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CritterManager.generated.h"

class UExplosiveSpoilsMutator;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCritterManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UExplosiveSpoilsMutator* ExplosiveSpoilsMutator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableCritters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationRange;
    
public:
    UCritterManager(const FObjectInitializer& ObjectInitializer);

};

