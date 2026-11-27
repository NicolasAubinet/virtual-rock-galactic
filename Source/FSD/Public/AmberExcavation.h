#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BatchSubObjective.h"
#include "EAmberDepositPhase.h"
#include "ERocketAttachmentState.h"
#include "AmberExcavation.generated.h"

class ARocketAttachment;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class FSD_API AAmberExcavation : public ABatchSubObjective {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARocketAttachment*> RocketAttachments;
    
public:
    AAmberExcavation(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetRocketAttachments(TArray<ARocketAttachment*> InRocketAttachments);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveExcavationPhaseComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveAttachmentPhaseComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnRocketAttachmentStateChanged(ERocketAttachmentState NewState);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void OnExcavationPhaseFinished();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<ARocketAttachment*> GetRocketAttachments() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<FVector> GetExcavationPoints() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<EAmberDepositPhase> GetCurrentPhase() const;
    
};

