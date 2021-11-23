// Fill out your copyright notice in the Description page of Project Settings.


#include "FSDPhysicsActor.h"

// Sets default values
AFSDPhysicsActor::AFSDPhysicsActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFSDPhysicsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFSDPhysicsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

