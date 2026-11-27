#include "FloatingTerrainChunk.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"
#include "SimpleHealthComponent.h"
#include "SimpleObjectInfoComponent.h"
#include "WalkableRotatingSceneComponent.h"

AFloatingTerrainChunk::AFloatingTerrainChunk(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->CharacterHitCooldown = 1.00f;
    this->TopSurfaceMaxAngle = 45.00f;
    this->Root = (USceneComponent*)RootComponent;
    this->IdleMotion = CreateDefaultSubobject<UWalkableRotatingSceneComponent>(TEXT("IdleMotion"));
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->Health = CreateDefaultSubobject<USimpleHealthComponent>(TEXT("Health"));
    this->InfoComponent = CreateDefaultSubobject<USimpleObjectInfoComponent>(TEXT("Info"));
    this->ChosenMaterial = NULL;
    this->ChunkPhysicalMaterial = NULL;
    this->DefaultBurntMaterial = NULL;
    this->DespawnDelay = 2.00f;
    this->BurntChance = 0.50f;
    this->MaxRandomDeltaYawOffset = 0.00f;
    this->MaxRandomBobbingSizeOffset = 0.00f;
    this->MaxRandomBobbingSpeedOffset = 0.00f;
    this->MinRandomScale = 1.00f;
    this->MaxRandomScale = 1.00f;
    this->MaxStartRoll = 180.00f;
    this->MaxStartPitch = 180.00f;
    this->RandomMeshScale = 1.00f;
    this->IdleBobbingSize = 0.00f;
    this->IdleBobbingSpeed = 0.00f;
    this->IdleMotion->SetupAttachment(RootComponent);
    this->Mesh->SetupAttachment(IdleMotion);
}

void AFloatingTerrainChunk::OnRep_RandomizedVisuals() {
}

void AFloatingTerrainChunk::OnHealthDepleted(UHealthComponentBase* HealthComponent) {
}

void AFloatingTerrainChunk::OnCharacterHit_Implementation(ACharacter* Character, const FHitResult& Hit, const FVector& HitDirection, bool bHitOnTop) {
}

void AFloatingTerrainChunk::Init(UBiome* Biome, const FRandomStream& RandomStream) {
}

void AFloatingTerrainChunk::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFloatingTerrainChunk, ChosenMaterial);
    DOREPLIFETIME(AFloatingTerrainChunk, RandomMeshRotation);
    DOREPLIFETIME(AFloatingTerrainChunk, RandomMeshScale);
    DOREPLIFETIME(AFloatingTerrainChunk, SelectedMesh);
    DOREPLIFETIME(AFloatingTerrainChunk, IdleDeltaRotationVector);
    DOREPLIFETIME(AFloatingTerrainChunk, IdleBobbingSize);
    DOREPLIFETIME(AFloatingTerrainChunk, IdleBobbingSpeed);
}


