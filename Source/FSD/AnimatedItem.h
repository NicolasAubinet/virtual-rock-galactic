// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "AnimatedItem.generated.h"

/**
 * 
 */
UCLASS()
class FSD_API AAnimatedItem : public AItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	USkeletalMeshComponent* FPMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USkeletalMeshComponent* TPMesh;

	UFUNCTION(BlueprintCallable) FTransform GetMuzzle() { FTransform dummy; return dummy; };
	
};
