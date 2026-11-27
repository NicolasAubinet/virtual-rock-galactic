#include "MindControlComponent.h"

UMindControlComponent::UMindControlComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CachedTree = NULL;
    this->Instigator = NULL;
}

AActor* UMindControlComponent::GetInstigator() const {
    return NULL;
}

UBehaviorTree* UMindControlComponent::GetCachedTree() const {
    return NULL;
}


