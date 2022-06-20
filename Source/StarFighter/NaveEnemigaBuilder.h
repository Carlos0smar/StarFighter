// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NaveEnemigaBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNaveEnemigaBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STARFIGHTER_API INaveEnemigaBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual class UAleronComponent* BuildAleron() = 0;
	virtual class UMotorComponent* BuildMotor() = 0;
	virtual class URandomMovementComponent* BuildMoveAhead() = 0;
	virtual class URandomMovementComponent_BP* BuildMoveRandom() = 0;


};
