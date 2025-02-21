#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Templates/SubclassOf.h"
#include "ActorTrackingComponent.generated.h"

class UActorTrackingWidget;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UActorTrackingComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActorTrackingWidget> WidgetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool VisibleOnHoldTAB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool VisibleFromStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIconHidden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorTrackingWidget> Widget;
    
public:
    UActorTrackingComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleIcon(bool Visible);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ShowAlwaysOn(bool IsActive);
    
    UFUNCTION(BlueprintCallable)
    void OnHoldTAB(bool IsDown);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsIconVisible() const;
    
};

