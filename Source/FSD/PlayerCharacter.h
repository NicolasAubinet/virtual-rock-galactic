// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Item.h"
#include "Components/WidgetInteractionComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FSD_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* FirstPersonCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* ThirdPersonCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) USkeletalMeshComponent* FPMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool IsPressingMovementInputKey;
	UFUNCTION(BlueprintCallable) void JumpPress() {};
	UFUNCTION(BlueprintCallable) void JumpRelease() {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetInteractionComponent* WidgetInteraction;
	
	UFUNCTION(BlueprintCallable) AItem* GetEquippedItem() { return nullptr; };};
