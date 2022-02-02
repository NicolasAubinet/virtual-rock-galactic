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

UENUM(BlueprintType)
enum class EAmmoWeaponState : uint8 {
	Equipping = 0,
	Ready = 1,
	Cycling = 2,
	Reloading = 3,
	BurstCycling = 4,
    EAmmoWeaponState_MAX = 5,
};

UENUM(BlueprintType)
enum class ECharacterState : uint8 {
    Walking = 0,
    Downed = 1,
    Dead = 2,
    Falling = 3,
    Paralyzed = 4,
    Using = 5,
    ZipLine = 6,
    NoMovement = 7,
    Grabbed = 8,
    Flying = 9,
    Frozen = 10,
    PassedOut = 11,
    Photography = 12,
    Piloting = 13,
    Attached = 14,
    Pushing = 15,
    TrackMovement = 16,
    EnemyControl = 17,
    Invalid = 18,
    ECharacterState_MAX = 19,
};

UENUM(BlueprintType)
enum class EShoutType : uint8 {
    Attention = 0,
    Follow = 1,
    StandingDown = 2,
    Downed = 3,
    RequestRevive = 4,
    Revived = 5,
    Resupply = 6,
    FriendlyFire = 7,
    KillCry = 8,
    Dead = 9,
    Cheating = 10,
    ResourceFull = 11,
    ResourceFullNoDonkey = 12,
    CallDonkey = 13,
    CallDonkey_NotInMission = 14,
    Depositing = 15,
    DepositingNoDonkey = 16,
    OutOfAmmo = 17,
    Reloading = 18,
    CharacterSelected = 19,
    UpgradeBought = 20,
    WaitingInDropPod = 21,
    Carrying = 22,
    EShoutType_MAX = 23,
};