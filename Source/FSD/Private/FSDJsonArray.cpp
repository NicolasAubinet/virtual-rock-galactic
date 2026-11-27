#include "FSDJsonArray.h"

UFSDJsonArray::UFSDJsonArray() {
}

UFSDJsonArray* UFSDJsonArray::CreateJSONArray(UObject* WorldContextObject) {
    return NULL;
}

bool UFSDJsonArray::Clear() {
    return false;
}

FString UFSDJsonArray::AsString() const {
    return TEXT("");
}

bool UFSDJsonArray::AddStringItem(const FString& Item) {
    return false;
}

bool UFSDJsonArray::AddStringArrayItem(const TArray<FString>& Item) {
    return false;
}

bool UFSDJsonArray::AddJSONObjectItem(const UFSDJsonObject* Item) {
    return false;
}

bool UFSDJsonArray::AddJSONArrayItem(const UFSDJsonArray* Item) {
    return false;
}

bool UFSDJsonArray::AddIntegerItem(int32 Item) {
    return false;
}

bool UFSDJsonArray::AddIntegerArrayItem(const TArray<int32>& Item) {
    return false;
}

bool UFSDJsonArray::AddFloatItem(float Item) {
    return false;
}

bool UFSDJsonArray::AddEmptyItem() {
    return false;
}

bool UFSDJsonArray::AddBooleanItem(bool Item) {
    return false;
}


