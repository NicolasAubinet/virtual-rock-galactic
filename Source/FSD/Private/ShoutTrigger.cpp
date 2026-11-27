#include "ShoutTrigger.h"
#include "Components/BoxComponent.h"

AShoutTrigger::AShoutTrigger(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    this->Shout = NULL;
    this->Audience = EShoutTriggerAudience::Everyone;
    this->CoolDown = -1.00f;
    this->bOncePerDwarf = false;
    this->bDirectional = false;
    this->bMissionControlPriority = true;
    this->bShareWithSameShout = true;
    this->Box = (UBoxComponent*)RootComponent;
}

void AShoutTrigger::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool AShoutTrigger::HasPlayed() const {
    return false;
}


