#include "MaterialDebugProbe.h"
#include "Components/SceneComponent.h"

AMaterialDebugProbe::AMaterialDebugProbe(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->bDebugEnabled = false;
    this->TraceDistance = 5000.00f;
    this->TraceInterval = 0.50f;
    this->TargetCamera = NULL;
}


