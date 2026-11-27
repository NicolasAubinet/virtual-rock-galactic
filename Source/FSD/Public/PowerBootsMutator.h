#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "PowerBootsMutator.generated.h"

class UPowerBootsMovementComponent;

UCLASS(Blueprintable, EditInlineNew)
class UPowerBootsMutator : public UMutator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UPowerBootsMovementComponent> ComponentClass;
    
public:
    UPowerBootsMutator();

};

