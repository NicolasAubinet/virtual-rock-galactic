#pragma once

#include "CoreMinimal.h"
#include "FSDGameInstance.generated.h"

UDELEGATE(BlueprintAuthorityOnly) DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLocalPlayerCharacterSet);

UCLASS()
class FSD_API UFSDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable) FOnLocalPlayerCharacterSet OnLocalPlayerCharacterSet;
};
