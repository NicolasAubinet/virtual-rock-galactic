#include "FloatingDebrisActor.h"
#include "Components/SceneComponent.h"
#include "Net/UnrealNetwork.h"
#include "WalkableRotatingSceneComponent.h"

AFloatingDebrisActor::AFloatingDebrisActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->RotatingScene = CreateDefaultSubobject<UWalkableRotatingSceneComponent>(TEXT("RotatingScene"));
    this->MaxRandomDeltaYawOffset = 0.00f;
    this->MaxRandomBobbingSizeOffset = 0.00f;
    this->MaxRandomBobbingSpeedOffset = 0.00f;
    this->MaxStartRoll = 180.00f;
    this->MaxStartPitch = 180.00f;
    this->IdleBobbingSize = 0.00f;
    this->IdleBobbingSpeed = 0.00f;
    this->RotatingScene->SetupAttachment(RootComponent);
}

void AFloatingDebrisActor::OnRep_IdleMotion() {
}

void AFloatingDebrisActor::InitFloatingActor_Implementation(const FRandomStream& RandomStream) {
}

void AFloatingDebrisActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFloatingDebrisActor, IdleDeltaRotationVector);
    DOREPLIFETIME(AFloatingDebrisActor, IdleBobbingSize);
    DOREPLIFETIME(AFloatingDebrisActor, IdleBobbingSpeed);
    DOREPLIFETIME(AFloatingDebrisActor, StartingRotation);
}


