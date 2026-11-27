#include "FissionVentItem.h"
#include "DamageComponent.h"
#include "FSDAudioComponent.h"
#include "Net/UnrealNetwork.h"

AFissionVentItem::AFissionVentItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Damage = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage"));
    this->ChargeState = EFissionChargeState::Idle;
    this->WindUpRate = 2.00f;
    this->WindUpMeterFraction = 0.25f;
    this->WindUpProgress = 0.00f;
    this->bWindUpComplete = false;
    this->Remote_ChargeUpProgress = 0.00f;
    this->LastBroadcastChargeMeter = -1.00f;
    this->AmmoBanked = 0;
    this->AmmoToBankNextTick = 0.00f;
    this->BaseChargeAmmoCost = 10;
    this->MaxChargeAmmoCost = 50;
    this->AmmoConsumptionRate = 10.00f;
    this->MaxChargeShotPower = 5.00f;
    this->MaxChargeAngleMultiplier = 2.50f;
    this->MaxChargeDamageTag = NULL;
    this->WeaponOverheatAnim = NULL;
    this->FP_ChargeupMontage = NULL;
    this->TP_ChargeupMontage = NULL;
    this->WindUpParticles = NULL;
    this->ChargeupParticles = NULL;
    this->FullChargeParticles = NULL;
    this->CooldownParticles = NULL;
    this->OverheatParticles = NULL;
    this->WindUpParticleInstance = NULL;
    this->ChargeupParticleInstance = NULL;
    this->FullChargeParticleInstance = NULL;
    this->CooldownParticleInstance = NULL;
    this->OverheatParticleInstance = NULL;
    this->WindUpAudioComponent = CreateDefaultSubobject<UFSDAudioComponent>(TEXT("WindUpAudioComponent"));
    this->ChargeUpAudioComponent = CreateDefaultSubobject<UFSDAudioComponent>(TEXT("ChargeUpAudioComponent"));
    this->FireAudioComponent = CreateDefaultSubobject<UFSDAudioComponent>(TEXT("FireAudioComponent"));
    this->TotalHeat = 0.00f;
    this->CoolingRate = 0.20f;
    this->HeatPerSecondWhileCharging = 0.05f;
    this->HeatPerSecondWhenCharged = 0.10f;
    this->HeatPerBaseChargeShot = 0.10f;
    this->HeatPerMaxChargeShot = 0.20f;
    this->ChargeUpAudioComponent->SetupAttachment(RootComponent);
    this->FireAudioComponent->SetupAttachment(RootComponent);
    this->WindUpAudioComponent->SetupAttachment(RootComponent);
}

void AFissionVentItem::Server_SetChargeState_Implementation(EFissionChargeState NewState) {
}

void AFissionVentItem::Server_ActivateMaxChargeDamageTag_Implementation(bool isMaxCharge) {
}






void AFissionVentItem::OnWindUpStarted_Implementation() {
}

void AFissionVentItem::OnWindUpEnded_Implementation() {
}

void AFissionVentItem::OnRep_ChargeState(EFissionChargeState oldState) {
}

void AFissionVentItem::OnFullyChargedEnded_Implementation() {
}

void AFissionVentItem::OnFullyCharged_Implementation() {
}

void AFissionVentItem::OnChargeStarted_Implementation() {
}

void AFissionVentItem::OnChargeEnded_Implementation() {
}

bool AFissionVentItem::GetIsWindingUp() const {
    return false;
}

bool AFissionVentItem::GetIsFullyCharged() const {
    return false;
}

bool AFissionVentItem::GetIsCharging() const {
    return false;
}

EFissionChargeState AFissionVentItem::GetChargeState() const {
    return EFissionChargeState::Idle;
}

float AFissionVentItem::GetChargeMeter() const {
    return 0.0f;
}

float AFissionVentItem::GetChargedShotPower() const {
    return 0.0f;
}

float AFissionVentItem::GetChargedHalfAngleMultiplier() const {
    return 0.0f;
}

float AFissionVentItem::GetBaseConeHalfAngle() const {
    return 0.0f;
}

void AFissionVentItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AFissionVentItem, ChargeState);
}


