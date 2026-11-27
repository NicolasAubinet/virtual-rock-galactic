#include "FSDCloudLoadSave.h"
#include "FSDCloudSaveHandler.h"

UFSDCloudLoadSave::UFSDCloudLoadSave() {
    this->CloudSaveHandler = CreateDefaultSubobject<UFSDCloudSaveHandler>(TEXT("CloudSaveHandler"));
}

void UFSDCloudLoadSave::StartCloudLoadForSlot(UObject* WorldContextObject, int32 Slot, int32 Offset) {
}

void UFSDCloudLoadSave::StartCloudLoadAll(UObject* WorldContextObject, int32 Offset) {
}


