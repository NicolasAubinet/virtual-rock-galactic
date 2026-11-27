#include "MonitoringStation_S07.h"
#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneComponent.h"
#include "DepressurerizationButton.h"
#include "InstantUsable.h"

AMonitoringStation_S07::AMonitoringStation_S07(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->AlarmWidgetTag = TEXT("AlarmScreen");
    this->MonitorShout = NULL;
    this->MonitorShoutChance = 40.00f;
    this->MonitorShoutCooldown = 10.00f;
    this->MonitorShoutDelay = 0.20f;
    this->TooManyTapsShout = NULL;
    this->TooManyTapsThreshold = 4;
    this->TooManyTapsChance = 50.00f;
    this->TooManyTapsCooldown = 5.00f;
    this->CachedMonitorUser = NULL;
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->AlarmLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("AlarmLight"));
    this->MonitorBox1 = CreateDefaultSubobject<UBoxComponent>(TEXT("MonitorBox1"));
    this->MonitorBox2 = CreateDefaultSubobject<UBoxComponent>(TEXT("MonitorBox2"));
    this->MonitorBox3 = CreateDefaultSubobject<UBoxComponent>(TEXT("MonitorBox3"));
    this->MonitorUsable1 = CreateDefaultSubobject<UInstantUsable>(TEXT("MonitorUsable1"));
    this->MonitorUsable2 = CreateDefaultSubobject<UInstantUsable>(TEXT("MonitorUsable2"));
    this->MonitorUsable3 = CreateDefaultSubobject<UInstantUsable>(TEXT("MonitorUsable3"));
    this->ButtonClass = ADepressurerizationButton::StaticClass();
    this->ButtonPlaceholderTag = TEXT("DP");
    this->VentLidOpenDuration = 0.40f;
    this->VentLidCloseDuration = 1.50f;
    this->VentLidOvershoot = 0.12f;
    this->Button = NULL;
    this->AlarmLight->SetupAttachment(RootComponent);
    this->MonitorBox1->SetupAttachment(RootComponent);
    this->MonitorBox2->SetupAttachment(RootComponent);
    this->MonitorBox3->SetupAttachment(RootComponent);
}

void AMonitoringStation_S07::StopScreenAlarm(float BlendTime) {
}

void AMonitoringStation_S07::StartScreenAlarm(const TArray<FMonitoringStationAlarmVector>& Parameters, float CyclesPerSecond, float MinLightIntensity, float MaxLightIntensity) {
}

void AMonitoringStation_S07::SetScreenVector(FName ParameterName, FLinearColor Value) {
}

void AMonitoringStation_S07::RegisterAlarmMaterials() {
}

void AMonitoringStation_S07::OnMonitorUsed(APlayerCharacter* User, EInputKeys Key) {
}

bool AMonitoringStation_S07::IsScreenAlarmActive() const {
    return false;
}

ADepressurerizationButton* AMonitoringStation_S07::GetButton() const {
    return NULL;
}

float AMonitoringStation_S07::GetAlarmPulse() const {
    return 0.0f;
}






