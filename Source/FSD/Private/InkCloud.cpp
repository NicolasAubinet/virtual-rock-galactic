#include "InkCloud.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "StatusEffectTriggerComponent.h"

AInkCloud::AInkCloud(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CloudCollider"));
    this->CloudCollider = (USphereComponent*)RootComponent;
    this->StatusTriggerComponent = CreateDefaultSubobject<UStatusEffectTriggerComponent>(TEXT("StatusEffectTrigger"));
    this->CloudEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("CloudEffect"));
    this->CloudDuration = 5.00f;
    this->FadeOutTime = 2.00f;
    this->CloudEffect->SetupAttachment(RootComponent);
}


