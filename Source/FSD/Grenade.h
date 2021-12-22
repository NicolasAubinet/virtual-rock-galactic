#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "Grenade.generated.h"

class UProjectileMovementComponent;

UCLASS()
class FSD_API AGrenade : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, Export, VisibleAnywhere) UProjectileMovementComponent* Movement;

	UPROPERTY(BlueprintReadOnly, EditAnywhere) TSubclassOf<AActor> WeaponPreviewClass;

	UFUNCTION(BlueprintCallable) static AGrenade* GetGrenadeDefaultObject(TSubclassOf<AGrenade> GrenadeClass) { return nullptr; }
};
