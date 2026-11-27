#include "DualMachinePistols.h"

ADualMachinePistols::ADualMachinePistols(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EmptyClipStatusEffect = NULL;
    this->RunAndGunSTE = NULL;
    this->EmptyClipMaxEnemiesFeared = -1;
    this->EmptyClipCourageFleeThreshold = 0.81f;
    this->EmptyClipFearShout = NULL;
}

void ADualMachinePistols::Server_TriggerStatusEffect_Implementation() {
}

void ADualMachinePistols::Server_TriggerFearOnNearbyEnemies_Implementation() {
}

void ADualMachinePistols::Server_NotifyClipEmptied_Implementation() {
}


void ADualMachinePistols::OnEmptyClipFearTriggered_Implementation(USceneComponent* AttachTo, float Radius, bool IsFirstPerson) {
}

void ADualMachinePistols::All_EmptyClipFearTriggered_Implementation() {
}

void ADualMachinePistols::All_ClipEmptied_Implementation() {
}


