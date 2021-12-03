// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WindowWidget.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShown);
UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNewTopWindow);
UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosed);

UCLASS()
class FSD_API UWindowWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) void ReceiveSelectPreviousCommand() {};
	UFUNCTION(BlueprintCallable) void ReceiveSelectNextCommand() {};
	UFUNCTION(BlueprintCallable) void ReceiveSelectCharacterCommand() {};
	UFUNCTION(BlueprintCallable) void ReceiveOkCommand() {};
	UFUNCTION(BlueprintCallable) void ReceiveCloseCommand() {};
	UPROPERTY(BlueprintAssignable) FOnShown OnShown;
	UPROPERTY(BlueprintAssignable) FOnNewTopWindow OnNewTopWindow;
	UPROPERTY(BlueprintAssignable) FOnClosed OnClosed;
	UFUNCTION(BlueprintCallable) void ConsumeCommand() {};
	UFUNCTION(BlueprintCallable) void CloseThisWindow() {};
};