// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "SpawnCapsula.h"
#include "SpawnCapsulaVida.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ASpawnCapsulaVida : public ASpawnCapsula
{
	GENERATED_BODY()
public:

	virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) override;

protected:
	virtual void BeginPlay() override;

	ASpawnCapsulaVida();

public:
	virtual void Tick(float DeltaTime) override;

};
