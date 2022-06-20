// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnCapsula.h"
#include "SpawnCapsulaEnergia.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ASpawnCapsulaEnergia : public ASpawnCapsula
{
	GENERATED_BODY()

public:


protected:
	virtual void BeginPlay() override;
	
	ASpawnCapsulaEnergia();

public:

	virtual void Tick(float DeltaTime) override;

	virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) override;
	
};
