#include "FSDJsonObject.h"

UFSDJsonObject::UFSDJsonObject() {
}

UFSDJsonObject* UFSDJsonObject::CreateJSONObject(UObject* WorldContextObject) {
    return NULL;
}

bool UFSDJsonObject::Clear() {
    return false;
}

FString UFSDJsonObject::AsString() const {
    return TEXT("");
}

bool UFSDJsonObject::AddStringField(const FString& Key, const FString& Value) {
    return false;
}

bool UFSDJsonObject::AddStringArrayField(const FString& Key, const TArray<FString>& Value) {
    return false;
}

bool UFSDJsonObject::AddJSONObjectField(const FString& Key, const UFSDJsonObject* Value) {
    return false;
}

bool UFSDJsonObject::AddJSONArrayField(const FString& Key, const UFSDJsonArray* Value) {
    return false;
}

bool UFSDJsonObject::AddIntegerField(const FString& Key, int32 Value) {
    return false;
}

bool UFSDJsonObject::AddIntegerArrayField(const FString& Key, const TArray<int32>& Value) {
    return false;
}

bool UFSDJsonObject::AddFloatField(const FString& Key, float Value) {
    return false;
}

bool UFSDJsonObject::AddFloatArrayField(const FString& Key, const TArray<float>& Value) {
    return false;
}

bool UFSDJsonObject::AddEmptyField(const FString& Key) {
    return false;
}

bool UFSDJsonObject::AddBooleanField(const FString& Key, bool Value) {
    return false;
}

bool UFSDJsonObject::AddBooleanArrayField(const FString& Key, const TArray<bool>& Value) {
    return false;
}


