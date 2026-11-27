#include "InstancedNiagaraComponent.h"

UInstancedNiagaraComponent::UInstancedNiagaraComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoActivate = true;
    this->NiagaraSystem = NULL;
    this->NiagaraComponent = NULL;
}

void UInstancedNiagaraComponent::SpawnSystemAtLocation(const FVector& InLocation) {
}

void UInstancedNiagaraComponent::SpawnEmittersAtLocation(const FVector& InLocation, const TArray<int32> emitterIndices) {
}


