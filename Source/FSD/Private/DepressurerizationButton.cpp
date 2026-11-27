#include "DepressurerizationButton.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DepressurerizationHoldUsable.h"
#include "DepressurerizationLidUsable.h"
#include "Net/UnrealNetwork.h"
#include "SpaceRigBlastShield.h"

ADepressurerizationButton::ADepressurerizationButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
    this->LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
    this->ProgressMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProgressMesh"));
    this->WarningLamps = CreateDefaultSubobject<USceneComponent>(TEXT("WarningLamps"));
    this->WarningLamp_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WarningLamp_1"));
    this->WarningLamp_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WarningLamp_2"));
    this->WarningLamp_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WarningLamp_3"));
    this->WarningLamp_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WarningLamp_4"));
    this->LidCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("LidCollider"));
    this->ButtonCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("ButtonCollider"));
    this->LidUsable = CreateDefaultSubobject<UDepressurerizationLidUsable>(TEXT("LidUsable"));
    this->ButtonUsable = CreateDefaultSubobject<UDepressurerizationHoldUsable>(TEXT("ButtonUsable"));
    this->LidFlipDuration = 0.35f;
    this->LidOvershoot = 0.12f;
    this->bLidCanBeClosed = true;
    this->VentDuration = 10.00f;
    this->LidFirstOpenedShout = NULL;
    this->VentStartedShout = NULL;
    this->VentStartedShoutDelay = 1.00f;
    this->VentStoppedShout = NULL;
    this->VentShoutDelay = 8.00f;
    this->VentPostProcessMaterial = NULL;
    this->VentPostProcessID = TEXT("Depressurerization");
    this->VentIntensityParameterName = TEXT("Master");
    this->VentPulseParameterName = TEXT("Intensity");
    this->VentFadeDuration = 1.50f;
    this->BlastShieldClass = ASpaceRigBlastShield::StaticClass();
    this->BlastShieldCloseDelay = 1.00f;
    this->BlastShieldOpenDelay = 0.00f;
    this->AudioLidOpen = NULL;
    this->AudioLidClose = NULL;
    this->AudioHold = NULL;
    this->AudioActivated = NULL;
    this->bDebugAllowRepeatActivation = false;
    this->ProgressParameterName = TEXT("Progress");
    this->LampPowerDuration = 1.00f;
    this->LampPowerParameterName = TEXT("Power");
    this->LampPowerOff = 0.00f;
    this->LampPowerOn = 1.00f;
    this->LampPowerVentMultiplier = 2.00f;
    this->LampVentBlinkRate = 6.00f;
    this->bLidOpen = false;
    this->bActivated = false;
    this->bVentActive = false;
    this->BlastShield = NULL;
    this->ProgressMID = NULL;
    this->VentPostProcessMID = NULL;
    this->HoldAudioInstance = NULL;
    this->BaseMesh->SetupAttachment(RootComponent);
    this->ButtonCollider->SetupAttachment(BaseMesh);
    this->LidCollider->SetupAttachment(LidMesh);
    this->LidMesh->SetupAttachment(BaseMesh);
    this->ProgressMesh->SetupAttachment(BaseMesh);
    this->WarningLamp_1->SetupAttachment(WarningLamps);
    this->WarningLamp_2->SetupAttachment(WarningLamps);
    this->WarningLamp_3->SetupAttachment(WarningLamps);
    this->WarningLamp_4->SetupAttachment(WarningLamps);
    this->WarningLamps->SetupAttachment(BaseMesh);
}

void ADepressurerizationButton::SetLidOpen(bool bOpen) {
}

void ADepressurerizationButton::ResetActivation() {
}

void ADepressurerizationButton::OnRep_VentActive() {
}

void ADepressurerizationButton::OnRep_LidOpen() {
}

void ADepressurerizationButton::OnRep_Activated() {
}

void ADepressurerizationButton::OnButtonUserCountChanged(int32 userCount) {
}

void ADepressurerizationButton::OnButtonUseEnded() {
}

void ADepressurerizationButton::OnButtonProgress(float Progress) {
}

void ADepressurerizationButton::OnButtonHoldCompleted(APlayerCharacter* User, EInputKeys Key) {
}

bool ADepressurerizationButton::IsVenting() const {
    return false;
}

bool ADepressurerizationButton::IsSpent() const {
    return false;
}

bool ADepressurerizationButton::IsLidOpen() const {
    return false;
}

EDepressurerizationLidState ADepressurerizationButton::GetLidState() const {
    return EDepressurerizationLidState::Closed;
}

ASpaceRigBlastShield* ADepressurerizationButton::GetBlastShield() const {
    return NULL;
}















void ADepressurerizationButton::All_HoldCancelled_Implementation() {
}

void ADepressurerizationButton::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADepressurerizationButton, bLidOpen);
    DOREPLIFETIME(ADepressurerizationButton, bActivated);
    DOREPLIFETIME(ADepressurerizationButton, bVentActive);
}


