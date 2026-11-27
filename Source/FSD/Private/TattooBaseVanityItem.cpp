#include "TattooBaseVanityItem.h"

UTattooBaseVanityItem::UTattooBaseVanityItem() {
    this->FlipTexture = false;
    this->TattooLocation = ETattooLocation::Arms;
}

void UTattooBaseVanityItem::PreviewTattoo(AFSDPlayerState* PlayerState, bool Show) const {
}


