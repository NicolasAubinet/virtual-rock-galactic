#pragma once
#include "CoreMinimal.h"
#include "PitchedUsers.generated.h"

class APlayerCharacter;

USTRUCT(BlueprintType)
struct FPitchedUsers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Player;
    
    FSD_API FPitchedUsers();
};

