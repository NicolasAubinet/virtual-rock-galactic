#include "HoopsGame.h"
#include "Net/UnrealNetwork.h"

AHoopsGame::AHoopsGame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsMovingRightServer = false;
    this->bIsMovingRightLocal = false;
    this->CurrentScore = 0;
    this->Cycle = 0;
    this->CycleLastScore = -1;
    this->ComboMultiplier = 1;
    this->ComboMax = 1;
    this->RedBarrelScore = 0;
    this->BlueBarrelScore = 0;
    this->BarrelComboCountAchievement = 0;
    this->ComboInitial = 1;
    this->NextFlipTimeServer = 0.00f;
    this->NextFlipTimeLocal = 0.00f;
    this->MoveTime = 0.00f;
    this->TimeToNextRandomScore = 0.00f;
    this->BP_BarrelSpawner = NULL;
    this->HoopHistory = NULL;
    this->Hoop = NULL;
    this->LastActivePlayer = NULL;
    this->ScoreWidget = NULL;
}


void AHoopsGame::Update(float DeltaTime, EComboFlow& outFLow) {
}

void AHoopsGame::StoreScore(int32 newScore) {
}

void AHoopsGame::Restart() {
}

void AHoopsGame::OnSpaceballInHoop(int32 scoreToAdd) {
}

void AHoopsGame::OnRep_Scores() {
}

void AHoopsGame::OnRep_IsMovingRightServer() {
}

void AHoopsGame::OnRep_CurrentScore() {
}

void AHoopsGame::OnRep_ComboMultiplier() {
}

void AHoopsGame::OnPlayerInHoop(APlayerCharacter* Player, UParticleSystem* deathEffect, bool& outIsDrunk, EPlayerFlowExecution& outFLow, APlayerCharacter*& outPlayer) {
}

void AHoopsGame::OnBarrelInHoop(APhysicsBarrel* Barrel, EBarrelFlowExecution& outFLow, float& outBarrelCombo, AFSDPlayerController*& outPlayerController) {
}

void AHoopsGame::OnBarglassInHoop(AActor* glass, AFSDPlayerController*& outPlayerController) {
}


void AHoopsGame::Init() {
}


void AHoopsGame::DataCellInHoop() {
}

void AHoopsGame::CollisionDirection(USceneComponent* Box, AActor* Target, EFlowFromDirection& outFLow, AActor*& outTarget) {
}


void AHoopsGame::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AHoopsGame, bIsMovingRightServer);
    DOREPLIFETIME(AHoopsGame, CurrentScore);
    DOREPLIFETIME(AHoopsGame, ComboMultiplier);
    DOREPLIFETIME(AHoopsGame, Scores);
    DOREPLIFETIME(AHoopsGame, NextFlipTimeServer);
}


