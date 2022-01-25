// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "Item.h"
#include "PickaxeItem.h"
#include "ThrownGrenadeItem.h"
#include "RessuplyPodItem.h"
#include "Flare.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<AItem*> Items;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) APickaxeItem* MiningItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ARessuplyPodItem* ResupplyItem;
	UPROPERTY(BlueprintReadOnly, Transient) AThrownGrenadeItem* GrenadeItem;
	UPROPERTY(BlueprintReadOnly, Transient) TSubclassOf<AFlare> flareClass;

	UFUNCTION(BlueprintCallable) void Equip(AItem* Item, bool ignoreIsUsing) {}
	UFUNCTION(BlueprintCallable) void Server_Equip(AItem* Item) {}
	UFUNCTION(BlueprintCallable) void Server_ThrowFlare() {}
};
