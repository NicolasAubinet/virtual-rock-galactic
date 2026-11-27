#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "EmitterConnection.h"
#include "InstancedNiagaraComponent.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInstancedNiagaraComponent : public USceneComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEmitterConnection> EmitterParameterConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
public:
    UInstancedNiagaraComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SpawnSystemAtLocation(const FVector& InLocation);
    
    UFUNCTION(BlueprintCallable)
    void SpawnEmittersAtLocation(const FVector& InLocation, const TArray<int32> emitterIndices);
    
};

