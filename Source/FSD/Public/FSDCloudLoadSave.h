#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SDCloudDelegateDelegate.h"
#include "SDCloudLoadDelegate.h"
#include "FSDCloudLoadSave.generated.h"

class UFSDCloudSaveHandler;

UCLASS(Blueprintable)
class UFSDCloudLoadSave : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSDCloudLoad OnSlotLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSDCloudDelegate OnCloudLoadFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSDCloudDelegate OnCloudLoadFinished;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UFSDCloudSaveHandler* CloudSaveHandler;
    
public:
    UFSDCloudLoadSave();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void StartCloudLoadForSlot(UObject* WorldContextObject, int32 Slot, int32 Offset);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void StartCloudLoadAll(UObject* WorldContextObject, int32 Offset);
    
};

