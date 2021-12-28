#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Item.h"
#include "PlayerHealthComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "InventoryComponent.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UPlayerHealthComponent* HealthComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UInventoryComponent* InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) USkeletalMeshComponent* FPMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool IsPressingMovementInputKey;
	UFUNCTION(BlueprintCallable) void JumpPress() {};
	UFUNCTION(BlueprintCallable) void JumpRelease() {};
	UFUNCTION(BlueprintCallable) void ThrowFlareReleased() {};
	UFUNCTION(BlueprintCallable) void ThrowFlarePressed() {};
	UFUNCTION(BlueprintCallable) void ThrowFlare() {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetInteractionComponent* WidgetInteraction;
	
	UFUNCTION(BlueprintCallable) AItem* GetEquippedItem() { return nullptr; }

	UFUNCTION(BlueprintCallable) bool IsMovementInputPressed() { return false; }
	UFUNCTION(BlueprintCallable) void ForceIsPressingMovementInputKey() {}

	UFUNCTION(BlueprintCallable) void Server_CallDonkey() {}
};
