#pragma once
#include "CoreMinimal.h"
#include "EProficiency.h"
#include "PerkAsset.h"
#include "ProficiencyPerkEffect.h"
#include "ProficiencyPerkAsset.generated.h"

class AFSDPlayerController;
class UFloatPerkAsset;
class UObject;

UCLASS(Blueprintable)
class UProficiencyPerkAsset : public UPerkAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProficiencyPerkEffect> Effects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProficiency Proficiency;
    
public:
    UProficiencyPerkAsset();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasUnlockedAllPerks(AFSDPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    float GetPerkValue(UObject* WorldContext) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static float GetFloatPerkValue(UObject* WorldContext, UFloatPerkAsset* Perk, float UnclaimedValue);
    
};

