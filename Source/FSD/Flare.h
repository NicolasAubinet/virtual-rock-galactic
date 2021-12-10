// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSDPhysicsActor.h"
#include "Item.h"
#include "Flare.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API AFlare : public AFSDPhysicsActor
{
	GENERATED_BODY()
	
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite) AItem* LoadoutItem;

		UFUNCTION(BlueprintCallable) void ActivateFlare() {};
};
