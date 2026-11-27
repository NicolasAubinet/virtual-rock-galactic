#include "GravityStabilizer.h"
#include "Components/SphereComponent.h"
#include "DamageComponent.h"
#include "SimpleHealthComponent.h"
#include "WalkableRotatingSceneComponent.h" // fixup: RotatingScene is only forward-declared, SetupAttachment needs the full type

AGravityStabilizer::AGravityStabilizer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RepulseTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("RepulseTrigger"));
    this->DamageCollider = CreateDefaultSubobject<USphereComponent>(TEXT("DamageCollider"));
    this->HealthComponent = CreateDefaultSubobject<USimpleHealthComponent>(TEXT("HealthComponent"));
    this->RepulseDamage = CreateDefaultSubobject<UDamageComponent>(TEXT("RepulseDamage"));
    this->RepulseInterval = 1.00f;
    this->RepulseEffect = NULL;
    this->CooldownEffect = NULL;
    this->CooldownDuration = 5.00f;
    this->CooldownEffectComponent = NULL;
    this->DamageCollider->SetupAttachment(RotatingScene);
    this->RepulseTrigger->SetupAttachment(RotatingScene);
}

void AGravityStabilizer::OnTriggered_Implementation() {
}

void AGravityStabilizer::OnRepulse_Implementation() {
}

bool AGravityStabilizer::IsOnCooldown() const {
    return false;
}

void AGravityStabilizer::HandleRepulseEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AGravityStabilizer::HandleRepulseBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AGravityStabilizer::HandleHit(float Damage, const FDamageData& DamageData, bool bAnyHealthLost) {
}

void AGravityStabilizer::All_StartCooldownEffect_Implementation() {
}

void AGravityStabilizer::All_PlayRepulseEffect_Implementation() {
}


