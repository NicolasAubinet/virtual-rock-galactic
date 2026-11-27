#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "indSessionsResultDelegate.h"
#include "FSDFindSessions.generated.h"

UCLASS(Blueprintable)
class UFSDFindSessions : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FindSessionsResult OnFindResult;
    
    UFSDFindSessions();

};

