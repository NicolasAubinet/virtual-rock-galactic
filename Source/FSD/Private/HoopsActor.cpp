#include "HoopsActor.h"
#include "Net/UnrealNetwork.h"

AHoopsActor::AHoopsActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsMovingRightServer = false;
    this->bIsMovingRightLocal = false;
    this->CurrentScore = 0;
    this->Cycle = 0;
    this->CycleLastScore = 0;
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
}




void AHoopsActor::OnRep_CurrentScoreNew() {
}



void AHoopsActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AHoopsActor, bIsMovingRightServer);
    DOREPLIFETIME(AHoopsActor, CurrentScore);
    DOREPLIFETIME(AHoopsActor, ComboMultiplier);
    DOREPLIFETIME(AHoopsActor, Scores);
    DOREPLIFETIME(AHoopsActor, NextFlipTimeServer);
}


