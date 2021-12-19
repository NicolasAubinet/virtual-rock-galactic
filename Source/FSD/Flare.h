#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "FSDPhysicsActor.h"
#include "Item.h"
#include "Flare.generated.h"

UCLASS()
class FSD_API AFlare : public AFSDPhysicsActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AItem> LoadoutItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TSubclassOf<AActor> WeaponPreviewClass;

	UFUNCTION(BlueprintCallable) void ActivateFlare() {}
	UFUNCTION(BlueprintCallable) static AFlare* GetFlareDefaultObject(TSubclassOf<AFlare> flareClass) { return nullptr; }
};
