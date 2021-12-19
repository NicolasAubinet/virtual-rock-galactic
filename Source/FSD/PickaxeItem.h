// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "PickaxeItem.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API APickaxeItem : public AItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite) USceneComponent* FP_Root;
};
