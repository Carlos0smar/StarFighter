// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveEnemiga.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveEnemiga : public ANave
{
	GENERATED_BODY()

	UPROPERTY()
		class ARandomMovementComponent* MoveHeadOn;

	UPROPERTY()
		class ARandomMovementComponent_BP* RandMove;

	UPROPERTY()
		class AAleronComponent* Aleron;

	UPROPERTY()
		class AMotorComponent* Motor;
};
