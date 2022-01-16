// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class FSD_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintCallable) void Server_StartUsing(bool IsUsing) {}
	UFUNCTION(BlueprintCallable) void RecieveStopUsing() {}
	UFUNCTION(BlueprintCallable) void RecieveStartUsing() {}
};
