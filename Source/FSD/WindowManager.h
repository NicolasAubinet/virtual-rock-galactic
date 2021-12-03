// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WindowWidget.h"
#include "Components/ActorComponent.h"
#include "WindowManager.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFirstWindowOpened);
UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLastWindowClosed);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FSD_API UWindowManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWindowManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintAssignable) FOnFirstWindowOpened OnFirstWindowOpened;
	UPROPERTY(EditAnywhere, BlueprintAssignable) FOnLastWindowClosed OnLastWindowClosed;

	UFUNCTION(BlueprintCallable) void OpenWindow(UWindowWidget* Window, bool PlayAudio, bool ShowCursor) {};
	UFUNCTION(BlueprintCallable) bool IsWindowOpen(UWindowWidget* Window) {return false;};
	UFUNCTION(BlueprintCallable) bool IsTopWindow(UWindowWidget* Window) {return false;};
	UFUNCTION(BlueprintCallable) void CloseWindow(UWindowWidget* Window) {};
	UFUNCTION(BlueprintCallable) void CloseTopWindow() {};
	UFUNCTION(BlueprintCallable) void CloseAllWindows() {};
	UFUNCTION(BlueprintCallable) UWindowWidget* GetCurrentWindow() {return nullptr;};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<UWindowWidget*> WindowStack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TMap<UWindowWidget*, UWindowWidget*> WindowList;
	UFUNCTION(BlueprintCallable) bool AnyWindowsOpen() {return false;};
};