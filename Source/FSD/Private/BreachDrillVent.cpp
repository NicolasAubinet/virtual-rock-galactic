#include "BreachDrillVent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BreachVentHealthComponent.h"
#include "Net/UnrealNetwork.h"
#include "ObjectAttackerPositioning.h"
#include "SimpleObjectInfoComponent.h"

ABreachDrillVent::ABreachDrillVent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->VentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VentMesh"));
    this->Health = CreateDefaultSubobject<UBreachVentHealthComponent>(TEXT("Health"));
    this->VentLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("VentLight"));
    this->ObjectInfo = CreateDefaultSubobject<USimpleObjectInfoComponent>(TEXT("ObjectInfo"));
    this->AttackerPositioning = CreateDefaultSubobject<UObjectAttackerPositioning>(TEXT("AttackerPositioning"));
    this->RepairUsableTag = TEXT("VentRepair");
    this->RepairIdleTimeout = 1.50f;
    this->RepairPerTick = 2.00f;
    this->VentGroup = 0;
    this->Repairing = false;
    this->DebugStartVulnerable = false;
    this->DebugAutoDamage = false;
    this->DebugAutoDamageAmount = 5.00f;
    this->DebugAutoDamageInterval = 1.00f;
    this->State = EBreachVentState::Sealed;
    this->VentOpen = false;
    this->VentLight->SetupAttachment(VentMesh);
    this->VentMesh->SetupAttachment(RootComponent);
}

void ABreachDrillVent::TickDebugDamage() {
}

void ABreachDrillVent::SetVulnerable(bool vulnerable) {
}

void ABreachDrillVent::SetVentGroup(int32 groupIndex) {
}

bool ABreachDrillVent::Repair(float amount) {
    return false;
}



void ABreachDrillVent::OnVentingChanged_Implementation(bool IsVenting) {
}


void ABreachDrillVent::OnRepairTick(APlayerCharacter* User, EInputKeys Key) {
}

void ABreachDrillVent::OnRep_VentOpen() {
}

void ABreachDrillVent::OnRep_State() {
}

void ABreachDrillVent::OnRep_Repairing() {
}

void ABreachDrillVent::OnHealthChanged(float newHealth) {
}


void ABreachDrillVent::OnDeath(UHealthComponentBase* HealthComponent) {
}

bool ABreachDrillVent::IsOpen() const {
    return false;
}

bool ABreachDrillVent::IsBroken() const {
    return false;
}

void ABreachDrillVent::HandleDebugPlayerSpawned(APlayerCharacter* PlayerCharacter) {
}

EBreachVentState ABreachDrillVent::GetVentState() const {
    return EBreachVentState::Sealed;
}

int32 ABreachDrillVent::GetVentGroup() const {
    return 0;
}

float ABreachDrillVent::GetHealthFraction() const {
    return 0.0f;
}

UBreachVentHealthComponent* ABreachDrillVent::GetHealth() const {
    return NULL;
}

void ABreachDrillVent::EndRepairing() {
}

void ABreachDrillVent::DebugSetAutoDamage(bool Enabled) {
}

bool ABreachDrillVent::CanBeRepaired() const {
    return false;
}

void ABreachDrillVent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ABreachDrillVent, VentGroup);
    DOREPLIFETIME(ABreachDrillVent, Repairing);
    DOREPLIFETIME(ABreachDrillVent, State);
    DOREPLIFETIME(ABreachDrillVent, VentOpen);
}


