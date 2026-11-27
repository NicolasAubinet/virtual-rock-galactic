#include "SeasonSave.h"

FSeasonSave::FSeasonSave() {
    this->SchematicsFixedUpInSeasonFive = 0;
    this->HasFixedUpRewardsRemovedInSeasonFiveV2 = false;
    this->HasFixedUpSeason3EventScripClaimed = false;
    this->HasFixedUpSeason3And4EventScripClaimedToGeneralization = false;
    this->ActiveSeason = 0;
    this->DesiredSeason = 0;
    this->bHasSeenSeason7 = false;
}

