// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrinkableActor.h"
#include "PlayerCharacter.h"
#include "GameFramework/Actor.h"
#include "SpaceRigBar.generated.h"

UCLASS()
class FSD_API ASpaceRigBar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceRigBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
