#include "PitJaw.h"
#include "Components/SkeletalMeshComponent.h"
#include "GrabberComponent.h"
#include "MeleeAttackComponent.h"
#include "MeshCarverComponent.h"
#include "Net/UnrealNetwork.h"

APitJaw::APitJaw(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    this->SkeletalMesh = (USkeletalMeshComponent*)RootComponent;
    this->GrabberComponent = CreateDefaultSubobject<UGrabberComponent>(TEXT("Grabber"));
    this->FirstBite = CreateDefaultSubobject<UMeleeAttackComponent>(TEXT("FirstBite"));
    this->Bite = CreateDefaultSubobject<UMeleeAttackComponent>(TEXT("Bite"));
    this->MouthCarve = CreateDefaultSubobject<UMeshCarverComponent>(TEXT("MouthCarve"));
    this->MinorCarve = CreateDefaultSubobject<UMeshCarverComponent>(TEXT("MinorCarve"));
    this->MajorCarve = CreateDefaultSubobject<UMeshCarverComponent>(TEXT("MajorCarve"));
    this->LungeDelay = 2.00f;
    this->GrabDelay = 0.10f;
    this->GrabDuration = 7.00f;
    this->BitesPerSecond = 0.50f;
    this->PostRelocateGracePeriod = 2.00f;
    this->LockOnDistance = 400.00f;
    this->LoseLockOnDistance = 500.00f;
    this->DownDetectDistance = 250.00f;
    this->UpDetectDistance = 400.00f;
    this->GrabDistance = 100.00f;
    this->GrabOffsetZ = 100.00f;
    this->DamageThresholdProgress = 0.00f;
    this->DamageThreshold = 300.00f;
    this->bUseQuickEscape = false;
    this->EscapeDelay = 3.50f;
    this->QuickEscapeDelay = 1.50f;
    this->RelocateDelayMin = 4.00f;
    this->RelocateDelayMax = 8.00f;
    this->RelocateMinDistSquared = 1500.00f;
    this->RelocateMaxDistSquared = 10000.00f;
    this->RelocateDelay = 0.00f;
    this->bDidMouthCarve = false;
    this->bDidMinorCarve = false;
    this->bDidMajorCarve = false;
    this->StateTime = 0.00f;
    this->State = EPitJawState::Idle;
    this->HealthTarget = NULL;
}

bool APitJaw::TryGetSafestRelocationPoint(FTransform& outSafestRelocationPoint) {
    return false;
}

void APitJaw::SpawnResourceChunk(UResourceData* Data, float Size, float DistanceFromMouth) {
}

void APitJaw::OnRep_State() {
}

void APitJaw::OnRelocationComplete() {
}

void APitJaw::OnPostAmbush() {
}

void APitJaw::OnHit(float Damage, const FDamageData& DamageData, bool anyHealthLost) {
}

void APitJaw::OnEscapeComplete() {
}

void APitJaw::OnDugOut() {
}

void APitJaw::OnDied(UHealthComponentBase* HealthComponent) {
}

EPitJawState APitJaw::GetState() const {
    return EPitJawState::Idle;
}

FVector APitJaw::GetMouthLocation_Implementation() const {
    return FVector{};
}

FVector APitJaw::GetMouthDirection_Implementation() const {
    return FVector{};
}

AActor* APitJaw::GetCurrentTarget() {
    return NULL;
}

void APitJaw::FindRelocationPoints(AProceduralSetup* pls, int32 desiredCandidates) {
}

void APitJaw::DoMouthCarve() {
}

void APitJaw::DoMinorCarve() {
}

void APitJaw::DoMajorCarve() {
}






void APitJaw::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APitJaw, RelocationPoints);
    DOREPLIFETIME(APitJaw, State);
    DOREPLIFETIME(APitJaw, Target);
}


