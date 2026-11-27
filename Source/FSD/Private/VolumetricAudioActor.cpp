#include "VolumetricAudioActor.h"
#include "Components/BoxComponent.h"
#include "VolumetricAudioComponent.h"

AVolumetricAudioActor::AVolumetricAudioActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    this->Box = (UBoxComponent*)RootComponent;
    this->VolumetricAudio = CreateDefaultSubobject<UVolumetricAudioComponent>(TEXT("VolumetricAudio"));
    this->VolumetricAudio->SetupAttachment(RootComponent);
}

UVolumetricAudioComponent* AVolumetricAudioActor::GetVolumetricAudio() const {
    return NULL;
}

UBoxComponent* AVolumetricAudioActor::GetBox() const {
    return NULL;
}


