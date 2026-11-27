#include "SoundAfflictionEffectIW.h"

USoundAfflictionEffectIW::USoundAfflictionEffectIW() {
    this->BeginSound = NULL;
    this->EndSound = NULL;
    this->PlayIn2D = false;
    this->VolumeMultiplier = 1.00f;
    this->PitchMultiplier = 1.00f;
    this->BeginSoundFadeOutTimeOnLoopEnd = 0.25f;
    this->CurrentAudioComponent = NULL;
}


