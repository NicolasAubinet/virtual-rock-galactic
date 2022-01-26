#pragma once

#include "CoreMinimal.h"
#include "FSD_struct.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class UPlayerHealthComponent;
class UInventoryComponent;
class UWidgetInteractionComponent;
class AItem;

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnManualMiningBegin);
UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnManualMiningEnd);
UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerCharacterOnCharacterStateChanged, ECharacterState, NewState);

UCLASS()
class FSD_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintAssignable) FOnManualMiningBegin OnManualMiningBegin;
	UPROPERTY(BlueprintAssignable) FOnManualMiningEnd OnManualMiningEnd;
	UPROPERTY(BlueprintAssignable) FPlayerCharacterOnCharacterStateChanged OnCharacterStateChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* FirstPersonCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UCameraComponent* ThirdPersonCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UPlayerHealthComponent* HealthComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UInventoryComponent* InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) USkeletalMeshComponent* FPMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool IsPressingMovementInputKey;
	UFUNCTION(BlueprintCallable) void JumpPress() {}
	UFUNCTION(BlueprintCallable) void JumpRelease() {}
	UFUNCTION(BlueprintCallable) void ThrowFlareReleased() {}
	UFUNCTION(BlueprintCallable) void ThrowFlarePressed() {}
	UFUNCTION(BlueprintCallable) void ThrowFlare() {}

	UFUNCTION(BlueprintCallable) void Server_SetUsing(bool characterIsUsing) {}
	UFUNCTION(BlueprintCallable) void Server_ThrowCarriedItem(FVector_NetQuantize force) {}

	UFUNCTION(BlueprintCallable) bool IsFirstPerson() { return false; }
	UFUNCTION(BlueprintCallable) bool IsDown() { return false; }
	UFUNCTION(BlueprintCallable) bool IsAlive() { return false; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetInteractionComponent* WidgetInteraction;
	
	UFUNCTION(BlueprintCallable) AItem* GetEquippedItem() { return nullptr; }

	UFUNCTION(BlueprintCallable) ECharacterState GetPreviousState() { return ECharacterState::Invalid; }
	UFUNCTION(BlueprintCallable) ECharacterState GetCurrentState() { return ECharacterState::Invalid; }

	UFUNCTION(BlueprintCallable) bool IsMovementInputPressed() { return false; }
	UFUNCTION(BlueprintCallable) void ForceIsPressingMovementInputKey() {}

	UFUNCTION(BlueprintCallable) void Server_CallDonkey() {}
};
