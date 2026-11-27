#include "SoundNodeCrossfadeLoop.h"

USoundNodeCrossfadeLoop::USoundNodeCrossfadeLoop() {
    this->CrossfadeDuration = 1.00f;
    this->Curve = ECrossfadeLoopCurve::EqualPower;
    this->bRandomizeStartPosition = true;
    this->RandomStartMin = 0.00f;
    this->RandomStartMax = 1.00f;
}


