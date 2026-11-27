#include "FSDGroundToAirEnemyController.h"
#include "Net/UnrealNetwork.h"

AFSDGroundToAirEnemyController::AFSDGroundToAirEnemyController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BehaviourTree = NULL;
    this->CurrentTarget = NULL;
}

void AFSDGroundToAirEnemyController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFSDGroundToAirEnemyController, CurrentTarget);
}


