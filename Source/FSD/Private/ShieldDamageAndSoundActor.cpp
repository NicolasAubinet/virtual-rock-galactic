#include "ShieldDamageAndSoundActor.h"
#include "Net/UnrealNetwork.h"

AShieldDamageAndSoundActor::AShieldDamageAndSoundActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->FieldCollider = NULL;
    this->MaxRadius = 400.00f;
    this->GrowDuration = 1.50f;
    this->StartRampDuration = 0.05f;
    this->ShrinkDelay = 0.20f;
    this->GrowthExponent = 3.00f;
    this->RadiusUpdateInterval = 0.10f;
    this->DamageInterval = 0.25f;
    this->EnemyStatusEffect = NULL;
    this->ShieldSystem = NULL;
    this->RadiusParameter = TEXT("Radius");
    this->CurrentRadius = 0.00f;
    this->FinalRadius = 0.00f;
}


void AShieldDamageAndSoundActor::OnTargetEndPlay(AActor* Actor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}

void AShieldDamageAndSoundActor::OnRep_Radius() {
}

void AShieldDamageAndSoundActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AShieldDamageAndSoundActor, CurrentRadius);
    DOREPLIFETIME(AShieldDamageAndSoundActor, FinalRadius);
}


