// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "CapsulaVida.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ACapsulaVida : public ACapsula
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	ACapsulaVida();
	
	virtual void Generar() override;

};
