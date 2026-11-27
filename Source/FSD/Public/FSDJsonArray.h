#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSDJsonArray.generated.h"

class UFSDJsonArray;
class UFSDJsonObject;

UCLASS(Blueprintable)
class UFSDJsonArray : public UObject {
    GENERATED_BODY()
public:
    UFSDJsonArray();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UFSDJsonArray* CreateJSONArray(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    bool Clear();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString AsString() const;
    
    UFUNCTION(BlueprintCallable)
    bool AddStringItem(const FString& Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddStringArrayItem(const TArray<FString>& Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddJSONObjectItem(const UFSDJsonObject* Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddJSONArrayItem(const UFSDJsonArray* Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddIntegerItem(int32 Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddIntegerArrayItem(const TArray<int32>& Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddFloatItem(float Item);
    
    UFUNCTION(BlueprintCallable)
    bool AddEmptyItem();
    
    UFUNCTION(BlueprintCallable)
    bool AddBooleanItem(bool Item);
    
};

