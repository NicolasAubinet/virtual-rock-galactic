#include "TunnelEventEnemySpawner.h"
#include "Components/SphereComponent.h"
#include "SpawnActorWithDebrisPosComponent.h"

ATunnelEventEnemySpawner::ATunnelEventEnemySpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<USphereComponent>(TEXT("SpawnSphere"))) {
    this->SpawnSphere = (USphereComponent*)RootComponent;
    this->SpawnComponent = CreateDefaultSubobject<USpawnActorWithDebrisPosComponent>(TEXT("SpawnComponent"));
    this->TunnelPlacementPositioning = NULL;
    this->TunnelPlacementCostCurve = NULL;
    this->EnemyPlacementPositioning = NULL;
    this->EnemyPlacementCostCurve = NULL;
    this->Base = 9.00f;
    this->PowerCoefficient = 2.00f;
    this->SpawnedtunnelInstance = NULL;
}

bool ATunnelEventEnemySpawner::TrySpawnEnemy() {
    return false;
}

void ATunnelEventEnemySpawner::StartTunnelSpawning() {
}

void ATunnelEventEnemySpawner::OnSpawnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}


