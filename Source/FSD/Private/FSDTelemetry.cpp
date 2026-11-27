#include "FSDTelemetry.h"

UFSDTelemetry::UFSDTelemetry() {
}

void UFSDTelemetry::Terminate() {
}

bool UFSDTelemetry::SubmitString(const FString& EventKey, const FString& EventData) {
    return false;
}

bool UFSDTelemetry::SubmitJSONObject(const FString& EventKey, const UFSDJsonObject* EventData) {
    return false;
}

bool UFSDTelemetry::SubmitInteger(const FString& EventKey, int32 EventData) {
    return false;
}

bool UFSDTelemetry::SubmitEmpty(const FString& EventKey) {
    return false;
}

bool UFSDTelemetry::Start(const FString& GameId, const FString& BuildID) {
    return false;
}

bool UFSDTelemetry::SetStateString(const FString& StateKey, const FString& StateData) {
    return false;
}

bool UFSDTelemetry::SetStateInteger(const FString& StateKey, int32 StateData) {
    return false;
}

bool UFSDTelemetry::SetStateFloat(const FString& StateKey, float StateData) {
    return false;
}

bool UFSDTelemetry::SetStateBoolean(const FString& StateKey, bool StateData) {
    return false;
}

bool UFSDTelemetry::SetOnlinePlatformUserID(const FString& OnlinePlatformUserID) {
    return false;
}

bool UFSDTelemetry::SetOnlinePlatformIdentifier(const FString& OnlinePlatformIdentifier) {
    return false;
}

void UFSDTelemetry::Resume() {
}

void UFSDTelemetry::Pause() {
}

bool UFSDTelemetry::IsTerminated() const {
    return false;
}

bool UFSDTelemetry::IsPaused() const {
    return false;
}

int64 UFSDTelemetry::GetTelemetryInstanceID() const {
    return 0;
}

FString UFSDTelemetry::GetOnlinePlatformIdentifier() const {
    return TEXT("");
}

UFSDTelemetry* UFSDTelemetry::CreateTelemetry(UObject* WorldContextObject) {
    return NULL;
}


