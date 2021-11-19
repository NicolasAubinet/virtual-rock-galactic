// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FSDPlayerState.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerCharacterSpawned);

UCLASS()
class FSD_API AFSDPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable) FOnPlayerCharacterSpawned OnPlayerCharacterSpawned;
	UPROPERTY(BlueprintReadWrite) bool HasSelectedCharacter;
	UPROPERTY(BlueprintReadWrite) bool bIsServer;
};
