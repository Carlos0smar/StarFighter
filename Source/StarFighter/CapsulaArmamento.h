// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaArmamento.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaArmamento : public ACapsula
{
	GENERATED_BODY()
public:
	ACapsulaArmamento();

	virtual void Generar() override;

protected:

	virtual void BeginPlay() override; 
};
