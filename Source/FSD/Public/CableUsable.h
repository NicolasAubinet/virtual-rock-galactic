#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CableDelegateDelegate.h"
#include "InstantUsable.h"
#include "Templates/SubclassOf.h"
#include "CableUsable.generated.h"

class ACable;
class ACableBuilderItem;
class ACableEnd;
class APlayerCharacter;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FSD_API UCableUsable : public UInstantUsable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableDelegate OnCableChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACableBuilderItem> BuilderItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ColliderName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CableStartComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CableSegment, meta=(AllowPrivateAccess=true))
    ACable* Cable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APlayerCharacter> InUseBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ACableEnd* DesignatedCableEnd;
    
public:
    UCableUsable(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CableSegment();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetStartTransform() const;
    
    UFUNCTION(BlueprintCallable)
    void FinishUse(APlayerCharacter* User, ACable* InCable);
    
};

