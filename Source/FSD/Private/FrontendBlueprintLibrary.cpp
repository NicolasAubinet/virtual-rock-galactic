#include "FrontendBlueprintLibrary.h"

UFrontendBlueprintLibrary::UFrontendBlueprintLibrary() {
}

void UFrontendBlueprintLibrary::OpenURLInExternalBrowser(const FString& URL) {
}

void UFrontendBlueprintLibrary::OpenURLInBrowserWithUTMTracking(const FString& URL, const FString& Location, const FString& trackingID) {
}

bool UFrontendBlueprintLibrary::IsShippingBuild() {
    return false;
}

void UFrontendBlueprintLibrary::GetStringFromClipboard(FString& fromClipboard) {
}

bool UFrontendBlueprintLibrary::FSDTargetPlatformIsXSX() {
    return false;
}

EFSDTargetPlatform UFrontendBlueprintLibrary::FSDTargetPlatform() {
    return EFSDTargetPlatform::Steam;
}

void UFrontendBlueprintLibrary::CopyStringToClipboard(const FString& toClipboard) {
}


