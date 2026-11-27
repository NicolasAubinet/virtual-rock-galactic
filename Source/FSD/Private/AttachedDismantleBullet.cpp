#include "AttachedDismantleBullet.h"
#include "Components/SceneComponent.h"
#include "DamageComponent.h"
#include "Net/UnrealNetwork.h"

AAttachedDismantleBullet::AAttachedDismantleBullet(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->ShrapnelDamage = CreateDefaultSubobject<UDamageComponent>(TEXT("ShrapnelDamage"));
    this->BurstDebrisParticle = NULL;
    this->DebrisMaterial = NULL;
}

void AAttachedDismantleBullet::OnShrapnelComplete() {
}

void AAttachedDismantleBullet::OnAttachedToPlate_Implementation(UMaterialInterface* PlateMaterial, UPrimitiveComponent* Plate) {
}

void AAttachedDismantleBullet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAttachedDismantleBullet, DebrisMaterial);
}


