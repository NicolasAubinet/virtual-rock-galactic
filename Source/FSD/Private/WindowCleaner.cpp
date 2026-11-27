#include "WindowCleaner.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "PaintableSurfaceComponent.h"

AWindowCleaner::AWindowCleaner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->Surface = CreateDefaultSubobject<UPaintableSurfaceComponent>(TEXT("Surface"));
    this->PaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaneMesh"));
    this->Carriage = CreateDefaultSubobject<USceneComponent>(TEXT("Carriage"));
    this->BotPivot = CreateDefaultSubobject<USceneComponent>(TEXT("BotPivot"));
    this->BotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BotMesh"));
    this->ArmMeshLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArmMeshLeft"));
    this->ArmMeshRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArmMeshRight"));
    this->BrushMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BrushMesh"));
    this->ColumnCount = 12;
    this->StampWidthScale = 1.15f;
    this->BotSpeed = 120.00f;
    this->BotDescendSpeed = 180.00f;
    this->BotAscendSpeed = 180.00f;
    this->StrokeBottomPause = 0.30f;
    this->MotionRampSeconds = 0.40f;
    this->StopOvershootCm = 6.00f;
    this->StopOvershootSettleSeconds = 0.60f;
    this->SoapShakeCm = 1.50f;
    this->SoapShakeFrequency = 18.00f;
    this->SoapStampOffsetCm = 0.00f;
    this->CleanStampOffsetCm = 0.00f;
    this->SoapCatchUpScale = 3.00f;
    this->BotSurfaceOffset = 10.00f;
    this->BotTiltSmoothing = 8.00f;
    this->ClientRenderDelay = 0.05f;
    this->ClientSmoothing = 15.00f;
    this->BotCelebrateParameterName = TEXT("Celebrate");
    this->FoldAngle = 20.00f;
    this->FoldOutDuration = 1.50f;
    this->FoldInDuration = 2.00f;
    this->FoldInDelay = 0.00f;
    this->BrushSpinSpeed = 720.00f;
    this->BrushSpinUpRate = 3.00f;
    this->BrushSpinDownRate = 1.50f;
    this->DirtLookAheadCm = 10.00f;
    this->RailMoveSound = NULL;
    this->SoapSound = NULL;
    this->WipeSound = NULL;
    this->CelebrationSound = NULL;
    this->CelebrationFinishedSound = NULL;
    this->WindowCleanedShout = NULL;
    this->bAutoScalePane = false;
    this->PaneMeshBaseSize = 100.00f;
    this->InitialDirt = 1.00f;
    this->CelebrationDuration = 6.00f;
    this->bCelebrationStartsAtLastColumn = true;
    this->CelebrationLoops = 5;
    this->CelebrationLoopTop = 0.35f;
    this->CelebrationLoopBottom = 0.80f;
    this->CelebrationSpinSpeed = 0.00f;
    this->BotMID = NULL;
    this->CelebrationAudio = NULL;
    this->ArmMeshLeft->SetupAttachment(Carriage);
    this->ArmMeshRight->SetupAttachment(Carriage);
    this->BotMesh->SetupAttachment(BotPivot);
    this->BotPivot->SetupAttachment(Carriage);
    this->BrushMesh->SetupAttachment(BotMesh);
    this->Carriage->SetupAttachment(RootComponent);
    this->PaneMesh->SetupAttachment(Surface);
    this->Surface->SetupAttachment(RootComponent);
}

void AWindowCleaner::SetFolded(bool bInFolded) {
}

void AWindowCleaner::OnRep_Motion() {
}

bool AWindowCleaner::IsViewUpGlassUp(FVector ViewForward, FVector ViewRight, FVector ViewUp) const {
    return false;
}

bool AWindowCleaner::IsViewRightGlassRight(FVector ViewForward, FVector ViewRight, FVector ViewUp) const {
    return false;
}

bool AWindowCleaner::IsSoaping() const {
    return false;
}

bool AWindowCleaner::IsSoapCatchingUp() const {
    return false;
}

bool AWindowCleaner::IsRemovingDirt() const {
    return false;
}

bool AWindowCleaner::IsMovingVertical() const {
    return false;
}

bool AWindowCleaner::IsMovingHorizontal() const {
    return false;
}

bool AWindowCleaner::IsLocked() const {
    return false;
}

bool AWindowCleaner::IsFolded() const {
    return false;
}

bool AWindowCleaner::IsFoldActive() const {
    return false;
}

bool AWindowCleaner::IsCleaning() const {
    return false;
}

bool AWindowCleaner::IsCelebrating() const {
    return false;
}

bool AWindowCleaner::IsBusy() const {
    return false;
}

bool AWindowCleaner::IsBotVisiblyMoving() const {
    return false;
}

void AWindowCleaner::HandleFullyCleaned() {
}

EWindowCleanerPhase AWindowCleaner::GetVisiblePhase() const {
    return EWindowCleanerPhase::Idle;
}

UPaintableSurfaceComponent* AWindowCleaner::GetSurface() const {
    return NULL;
}

int32 AWindowCleaner::GetColumnCount() const {
    return 0;
}

FVector2D AWindowCleaner::GetBrushVisualUV() const {
    return FVector2D{};
}

float AWindowCleaner::GetBrushSpinFraction() const {
    return 0.0f;
}

FVector AWindowCleaner::GetBotVelocity() const {
    return FVector{};
}

float AWindowCleaner::GetArmExtentCm() const {
    return 0.0f;
}

float AWindowCleaner::GetArmExtent() const {
    return 0.0f;
}

void AWindowCleaner::DebugToggleFastClean() {
}

bool AWindowCleaner::Command(EWindowCleanerCommand InCommand, APlayerCharacter* User) {
    return false;
}














void AWindowCleaner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AWindowCleaner, Motion);
}


