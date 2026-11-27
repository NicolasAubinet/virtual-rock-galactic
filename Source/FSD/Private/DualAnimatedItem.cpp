#include "DualAnimatedItem.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "FirstPersonSkeletalMeshComponent.h"
#include "SkinnableComponent.h"

ADualAnimatedItem::ADualAnimatedItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->FPAnimInstance = NULL;
    this->TPAnimInstance = NULL;
    this->FPRMesh = CreateDefaultSubobject<UFirstPersonSkeletalMeshComponent>(TEXT("FPRMesh"));
    this->FPLMesh = CreateDefaultSubobject<UFirstPersonSkeletalMeshComponent>(TEXT("FPLMesh"));
    this->TPRMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TPRMesh"));
    this->TPLMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TPLMesh"));
    this->Skinnable = CreateDefaultSubobject<USkinnableComponent>(TEXT("Skinnable"));
    this->FP_EquipAnimation = NULL;
    this->TP_EquipAnimation = NULL;
    this->EquipDuration = 0.25f;
    this->CharacterAnimationSet = NULL;
    this->FPLMesh->SetupAttachment(RootComponent);
    this->FPRMesh->SetupAttachment(RootComponent);
    this->TPLMesh->SetupAttachment(RootComponent);
    this->TPRMesh->SetupAttachment(RootComponent);
}

USkeletalMeshComponent* ADualAnimatedItem::GetRItemMesh() const {
    return NULL;
}

USkeletalMeshComponent* ADualAnimatedItem::GetLItemMesh() const {
    return NULL;
}


