// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnCapsula.h"
#include "SpawnCapsulaArmamento.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ASpawnCapsulaArmamento : public ASpawnCapsula
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
	ASpawnCapsulaArmamento();

public:
	virtual void Tick(float DeltaTime) override;

    virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) ;
	
};
