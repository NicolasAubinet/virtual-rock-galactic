#pragma once
#include "CoreMinimal.h"
#include "EmitterConnection.h"
#include "InstancedNiagaraSystemSettings.generated.h"

USTRUCT(BlueprintType)
struct FInstancedNiagaraSystemSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEmitterConnection> EmitterParamConnections;
    
    FSD_API FInstancedNiagaraSystemSettings();
};

