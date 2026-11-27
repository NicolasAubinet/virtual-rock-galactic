#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "RagdollImpactMutator.generated.h"

class URagdollImpactComponent;

UCLASS(Blueprintable, EditInlineNew)
class URagdollImpactMutator : public UMutator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<URagdollImpactComponent> ComponentClass;
    
public:
    URagdollImpactMutator();

};

