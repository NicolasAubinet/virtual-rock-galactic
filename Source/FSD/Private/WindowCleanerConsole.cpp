#include "WindowCleanerConsole.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "ProximityMissionShoutComponent.h"
#include "WindowCleanerButton.h"

AWindowCleanerConsole::AWindowCleanerConsole(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->PedestalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PedestalMesh"));
    this->ScreenHousing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScreenHousing"));
    this->ProgressMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProgressMesh"));
    this->IntroShout = CreateDefaultSubobject<UProximityMissionShoutComponent>(TEXT("IntroShout"));
    this->ButtonLeft = CreateDefaultSubobject<UWindowCleanerButton>(TEXT("ButtonLeft"));
    this->ButtonRight = CreateDefaultSubobject<UWindowCleanerButton>(TEXT("ButtonRight"));
    this->ButtonClean = CreateDefaultSubobject<UWindowCleanerButton>(TEXT("ButtonClean"));
    this->ColliderLeft = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderLeft"));
    this->ColliderRight = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderRight"));
    this->ColliderClean = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderClean"));
    this->ButtonMeshLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMeshLeft"));
    this->ButtonMeshRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMeshRight"));
    this->ButtonMeshClean = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMeshClean"));
    this->Cleaner = NULL;
    this->AutoDetectRetryInterval = 1.00f;
    this->VentStation = NULL;
    this->ButtonPressDepth = 2.00f;
    this->ButtonPressDelay = 0.00f;
    this->ButtonPressDuration = 0.15f;
    this->CommandDelay = 0.45f;
    this->PredictedPressTimeout = 1.00f;
    this->ScreenMaterial = NULL;
    this->ScreenImageName = TEXT("Image_Minimap");
    this->ScreenMaskParameterName = TEXT("GrimeMask");
    this->ScreenCleanRatioParameterName = TEXT("CleanRatio");
    this->ScreenBotUVParameterName = TEXT("BotUV");
    this->ScreenMovingParameterName = TEXT("Moving");
    this->ScreenLayoutParameterName = TEXT("WindowLayout");
    this->ScreenFlipParameterName = TEXT("FlipUV");
    this->PressCounters.AddDefaulted(3);
    this->ScreenMID = NULL;
    this->ProgressMID = NULL;
    this->ButtonMeshClean->SetupAttachment(ColliderClean);
    this->ButtonMeshLeft->SetupAttachment(ColliderLeft);
    this->ButtonMeshRight->SetupAttachment(ColliderRight);
    this->ColliderClean->SetupAttachment(PedestalMesh);
    this->ColliderLeft->SetupAttachment(PedestalMesh);
    this->ColliderRight->SetupAttachment(PedestalMesh);
    this->IntroShout->SetupAttachment(RootComponent);
    this->PedestalMesh->SetupAttachment(RootComponent);
    this->ProgressMesh->SetupAttachment(PedestalMesh);
    this->ScreenHousing->SetupAttachment(RootComponent);
}

void AWindowCleanerConsole::SetCleaner(AWindowCleaner* InCleaner) {
}

void AWindowCleanerConsole::OnRep_PressCounters() {
}

bool AWindowCleanerConsole::IsVentLockoutActive() const {
    return false;
}

AWindowCleaner* AWindowCleanerConsole::GetCleaner() const {
    return NULL;
}



void AWindowCleanerConsole::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AWindowCleanerConsole, Cleaner);
    DOREPLIFETIME(AWindowCleanerConsole, PressCounters);
}


