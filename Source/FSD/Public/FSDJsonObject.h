#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSDJsonObject.generated.h"

class UFSDJsonArray;
class UFSDJsonObject;

UCLASS(Blueprintable)
class UFSDJsonObject : public UObject {
    GENERATED_BODY()
public:
    UFSDJsonObject();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UFSDJsonObject* CreateJSONObject(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool Clear();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString AsString() const;
    
    UFUNCTION(BlueprintCallable)
    bool AddStringField(const FString& Key, const FString& Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddStringArrayField(const FString& Key, const TArray<FString>& Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddJSONObjectField(const FString& Key, const UFSDJsonObject* Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddJSONArrayField(const FString& Key, const UFSDJsonArray* Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddIntegerField(const FString& Key, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddIntegerArrayField(const FString& Key, const TArray<int32>& Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddFloatField(const FString& Key, float Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddFloatArrayField(const FString& Key, const TArray<float>& Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddEmptyField(const FString& Key);
    
    UFUNCTION(BlueprintCallable)
    bool AddBooleanField(const FString& Key, bool Value);
    
    UFUNCTION(BlueprintCallable)
    bool AddBooleanArrayField(const FString& Key, const TArray<bool>& Value);
    
};

