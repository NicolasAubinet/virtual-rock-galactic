#include "HangingFireCracker.h"
#include "Components/SkeletalMeshComponent.h"
#include "NiagaraComponent.h"
#include "FSDAudioComponent.h"
#include "InstantUsable.h"

AHangingFireCracker::AHangingFireCracker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Root"));
    this->Usable = CreateDefaultSubobject<UInstantUsable>(TEXT("Usable"));
    this->SKMesh = (USkeletalMeshComponent*)RootComponent;
    this->MovingSparks = CreateDefaultSubobject<UNiagaraComponent>(TEXT("MovingSparks"));
    this->FuseSound = CreateDefaultSubobject<UFSDAudioComponent>(TEXT("FuseSound"));
    this->CrackerExplosion = NULL;
    this->CrackerExplosionCue = NULL;
    this->SparkSpeed = 20.00f;
    this->ExplodeRange = 40.00f;
    this->ExplodeImpulse = 100.00f;
    this->FuseSound->SetupAttachment(MovingSparks);
    this->MovingSparks->SetupAttachment(RootComponent);
}

void AHangingFireCracker::StartFire() {
}


