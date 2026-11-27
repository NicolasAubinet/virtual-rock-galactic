#include "DebugTeleportPoint.h"
#include "Components/SceneComponent.h"

ADebugTeleportPoint::ADebugTeleportPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsEditorOnlyActor = true;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
}


