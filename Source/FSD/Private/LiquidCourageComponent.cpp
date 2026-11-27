#include "LiquidCourageComponent.h"

ULiquidCourageComponent::ULiquidCourageComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DrinkItem = NULL;
    this->DrinkItemInstance = NULL;
}

void ULiquidCourageComponent::OnDrinkItemInstanced(AItem* itemInstance) {
}

void ULiquidCourageComponent::OnDrinkItemChargesChanged(int32 newCharges) {
}


