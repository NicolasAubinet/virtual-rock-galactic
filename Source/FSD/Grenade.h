#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "Grenade.generated.h"

UCLASS()
class FSD_API AGrenade : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite) AActor* WeaponPreviewClass;

	UFUNCTION(BlueprintCallable) static AGrenade* GetGrenadeDefaultObject(TSubclassOf<AGrenade> GrenadeClass) { return nullptr; }
};
