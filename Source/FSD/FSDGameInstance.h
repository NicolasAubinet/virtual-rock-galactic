#pragma once

#include "CoreMinimal.h"
#include "WindowWidget.h"
#include "FSDGameInstance.generated.h"

class UGeneratedMission;

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalPlayerCharacterSet);
UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFSDGameInstanceOnShowEndScreen);

UCLASS()
class FSD_API UFSDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FOnLocalPlayerCharacterSet OnLocalPlayerCharacterSet;
	UPROPERTY(BlueprintAssignable) FFSDGameInstanceOnShowEndScreen OnShowEndScreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TWeakObjectPtr<UWindowWidget> ActiveEscapeMenu;

	UFUNCTION(BlueprintCallable) void SetSelectedMission(UGeneratedMission* mission, bool updateSessionSettings) {}
};
