// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EHUDVisibilityReason : uint8 {
	Invalid = 0,
	UserChoice = 1,
	StandDown = 2,
	MenuActive = 4,
	Photography = 8,
	EHUDVisibilityReason_MAX = 9
};

UENUM(BlueprintType)
enum class EInputKeys : uint8 {
	Use = 0,
	Fire = 1,
	Mine = 2,
	EInputKeys_MAX = 255
};