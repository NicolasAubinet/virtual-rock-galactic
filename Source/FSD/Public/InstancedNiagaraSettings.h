#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InstancedNiagaraSystemSettings.h"
#include "InstancedNiagaraSettings.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable)
class UInstancedNiagaraSettings : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UNiagaraSystem*, FInstancedNiagaraSystemSettings> SystemSettings;
    
public:
    UInstancedNiagaraSettings();

};

