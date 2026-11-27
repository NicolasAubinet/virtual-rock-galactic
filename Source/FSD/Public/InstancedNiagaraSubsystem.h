#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "InstancedNiagaraSubsystem.generated.h"

class UInstancedNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable)
class UInstancedNiagaraSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<UNiagaraSystem*, UInstancedNiagaraComponent*> SystemToComponent;
    
public:
    UInstancedNiagaraSubsystem();

};

