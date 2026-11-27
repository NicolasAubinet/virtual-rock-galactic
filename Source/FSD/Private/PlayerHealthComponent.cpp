#include "PlayerHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

UPlayerHealthComponent::UPlayerHealthComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SecondChanceDamageCap = 750.00f;
    this->MaxHealth = 100.00f;
    this->MaxArmor = 0.00f;
    this->ArmorDamage = 0.00f;
    this->ReviveHealthReturnRatio = 1.00f;
    this->ReviveArmorReturnRatio = 1.00f;
    this->HealthPerCrystalVolume = 0.25f;
    this->ArmorRegenCurve = NULL;
    this->ShieldRegenDelay = 5.00f;
    this->Character = NULL;
    this->GenericImpactParticles = NULL;
    this->ShieldLinkEffect = NULL;
    this->AudioShieldGainedFromSmallKill = NULL;
    this->AudioShieldGainedFromLargeKill = NULL;
    this->ShieldGainedFromKillSoundMix = NULL;
    this->ShieldLinkInstance = NULL;
    this->InvulnerabilityDuration = 0.25f;
    this->ReviveInvulnerabilityTime = 3.00f;
    this->DamageTakenMutator = NULL;
    this->IronWillStatusEffectClass = NULL;
    this->IronWillStatusEffect = NULL;
    this->IronWillActive = false;
    this->IronWillTimeToActivate = 0.00f;
    this->SecondChanceStatusEffectClass = NULL;
    this->SecondChanceStatusEffect = NULL;
    this->SecondChanceDuration = -1.00f;
    this->SecondChanceActive = false;
    this->SharedHealthMutator = NULL;
}

UStatusEffect* UPlayerHealthComponent::SetSecondChanceStatusEffect(TSubclassOf<UStatusEffect> steClass) {
    return NULL;
}

UStatusEffect* UPlayerHealthComponent::SetIronWillStatusEffect(TSubclassOf<UStatusEffect> steClass) {
    return NULL;
}

void UPlayerHealthComponent::SetInvulnerable(float Duration) {
}

void UPlayerHealthComponent::Server_TryActivateSecondChance_Implementation() {
}

void UPlayerHealthComponent::Server_TryActivateIronWill_Implementation() {
}

void UPlayerHealthComponent::OnRep_MaxHealth() {
}

void UPlayerHealthComponent::OnRep_MaxArmor() {
}

void UPlayerHealthComponent::OnRep_ArmorDamage(float oldDamage) {
}

void UPlayerHealthComponent::OnEnemyKilled(const FGameplayTagContainer& enemyTags, AActor* killedEnemy) {
}

bool UPlayerHealthComponent::IsLowHealth() const {
    return false;
}

float UPlayerHealthComponent::GetSecondChanceTimeRemaining() const {
    return 0.0f;
}

float UPlayerHealthComponent::GetSecondChanceDuration() const {
    return 0.0f;
}

bool UPlayerHealthComponent::GetSecondChanceActive() const {
    return false;
}

float UPlayerHealthComponent::GetRemainingIronWillActivationTime() const {
    return 0.0f;
}

bool UPlayerHealthComponent::GetIsHealthRegenerating() const {
    return false;
}

bool UPlayerHealthComponent::GetIronWillActive() const {
    return false;
}

float UPlayerHealthComponent::GetHealthRegeneratingTargetRatio() const {
    return 0.0f;
}

void UPlayerHealthComponent::Client_ShieldGainedFromKill_Implementation(float amount, bool isLargeEnemy) {
}

void UPlayerHealthComponent::Client_SetHealthRegenerating_Implementation(bool isRegenerating) {
}

void UPlayerHealthComponent::Client_OnFriendlyFire_Implementation(AController* EventInstigator, AActor* DamageCauser) {
}

void UPlayerHealthComponent::Client_HealthFullCannotHeal_Implementation() {
}

bool UPlayerHealthComponent::CanActivateSecondChance() const {
    return false;
}

bool UPlayerHealthComponent::CanActivateIronWill() const {
    return false;
}

void UPlayerHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UPlayerHealthComponent, MaxHealth);
    DOREPLIFETIME(UPlayerHealthComponent, MaxArmor);
    DOREPLIFETIME(UPlayerHealthComponent, ArmorDamage);
    DOREPLIFETIME(UPlayerHealthComponent, IronWillActive);
    DOREPLIFETIME(UPlayerHealthComponent, SecondChanceDuration);
    DOREPLIFETIME(UPlayerHealthComponent, SecondChanceActive);
}


