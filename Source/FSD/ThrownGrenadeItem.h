#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Item.h"
#include "Grenade.h"
#include "ThrownGrenadeItem.generated.h"

UCLASS()
class FSD_API AThrownGrenadeItem : public AItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Export, Transient) UStaticMeshComponent* GrenadeMeshInstance;

	UPROPERTY(BlueprintReadOnly, Transient) TSubclassOf<AGrenade> GrenadeClass;

	UFUNCTION(BlueprintCallable) void Server_ThrowGrenade() {}
};
