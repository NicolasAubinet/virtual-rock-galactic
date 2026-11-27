#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSDTelemetry.generated.h"

class UFSDJsonObject;
class UFSDTelemetry;

UCLASS(Blueprintable)
class UFSDTelemetry : public UObject {
    GENERATED_BODY()
public:
    UFSDTelemetry();

    UFUNCTION(BlueprintCallable)
    void Terminate();
    
    UFUNCTION(BlueprintCallable)
    bool SubmitString(const FString& EventKey, const FString& EventData);
    
    UFUNCTION(BlueprintCallable)
    bool SubmitJSONObject(const FString& EventKey, const UFSDJsonObject* EventData);
    
    UFUNCTION(BlueprintCallable)
    bool SubmitInteger(const FString& EventKey, int32 EventData);
    
    UFUNCTION(BlueprintCallable)
    bool SubmitEmpty(const FString& EventKey);
    
    UFUNCTION(BlueprintCallable)
    bool Start(const FString& GameId, const FString& BuildID);
    
    UFUNCTION(BlueprintCallable)
    bool SetStateString(const FString& StateKey, const FString& StateData);
    
    UFUNCTION(BlueprintCallable)
    bool SetStateInteger(const FString& StateKey, int32 StateData);
    
    UFUNCTION(BlueprintCallable)
    bool SetStateFloat(const FString& StateKey, float StateData);
    
    UFUNCTION(BlueprintCallable)
    bool SetStateBoolean(const FString& StateKey, bool StateData);
    
    UFUNCTION(BlueprintCallable)
    bool SetOnlinePlatformUserID(const FString& OnlinePlatformUserID);
    
    UFUNCTION(BlueprintCallable)
    bool SetOnlinePlatformIdentifier(const FString& OnlinePlatformIdentifier);
    
    UFUNCTION(BlueprintCallable)
    void Resume();
    
    UFUNCTION(BlueprintCallable)
    void Pause();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTerminated() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPaused() const;
    
    UFUNCTION(BlueprintPure)
    int64 GetTelemetryInstanceID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetOnlinePlatformIdentifier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UFSDTelemetry* CreateTelemetry(UObject* WorldContextObject);
    
};

