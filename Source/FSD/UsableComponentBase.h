// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Components/ActorComponent.h"
#include "FSD_struct.h"
#include "UsableComponentBase.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UUsableComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUsableComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable) void SetRayTraceTriggered(bool rayTraceTriggered) {};
	UFUNCTION(BlueprintCallable) FText GetUseText(APlayerCharacter* User) {return FText();};
	UFUNCTION(BlueprintCallable) float GetUseProgressInPercent(APlayerCharacter* User) {return 0.f;};
	UFUNCTION(BlueprintCallable) UTexture2D* GetUsableIcon() {return nullptr;};
	UFUNCTION(BlueprintCallable) bool GetShowUsingUI() {return false;};
	UFUNCTION(BlueprintCallable) bool GetIsRayTraceTriggerd() {return false;};
	UFUNCTION(BlueprintCallable) bool GetHideProgressBar(APlayerCharacter* User) {return false;};
	UFUNCTION(BlueprintCallable) bool GetHideActionText(APlayerCharacter* User) {return false;};
	UFUNCTION(BlueprintCallable) void EndUse(APlayerCharacter* User) {};
    UFUNCTION(BlueprintCallable) void BeginUse(APlayerCharacter* User, enum EInputKeys Key) {};	
};