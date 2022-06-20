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

public:
	UPROPERTY()
		class URandomMovementComponent* MoveAhead;

	UPROPERTY()
		class URandomMovementComponent_BP* RandMove;

	UPROPERTY()
		class UAleronComponent* Aleron;

	UPROPERTY()
		class UMotorComponent* Motor;

	//void FeaturesNaveENemiga();
};
