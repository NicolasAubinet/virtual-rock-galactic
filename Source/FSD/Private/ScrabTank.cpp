#include "ScrabTank.h"
#include "Components/SceneComponent.h"
#include "Components/SplineComponent.h"

AScrabTank::AScrabTank(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->PathSpline = CreateDefaultSubobject<USplineComponent>(TEXT("PathSpline"));
    this->BeetleMount = CreateDefaultSubobject<USceneComponent>(TEXT("BeetleMount"));
    this->BeetleVisual = CreateDefaultSubobject<USceneComponent>(TEXT("BeetleVisual"));
    this->MoveSpeedUUPerSec = 200.00f;
    this->EaseExponent = 2.00f;
    this->bOrientToSpline = true;
    this->bYawOnly = true;
    this->FacingYawOffsetDeg = 0.00f;
    this->VisualRotInterpSpeed = 10.00f;
    this->InitialSlot = EScrabTankSlot::Left;
    this->CenterNormalized = 0.50f;
    this->BeetleMount->SetupAttachment(RootComponent);
    this->BeetleVisual->SetupAttachment(BeetleMount);
    this->PathSpline->SetupAttachment(RootComponent);
}

void AScrabTank::TabRight() {
}

void AScrabTank::TabLeft() {
}

USceneComponent* AScrabTank::GetBeetleMount() const {
    return NULL;
}

USceneComponent* AScrabTank::GetBeetleAttach() const {
    return NULL;
}

void AScrabTank::Feed() {
}





