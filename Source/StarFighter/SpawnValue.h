// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnValue.generated.h"

UCLASS()
class STARFIGHTER_API ASpawnValue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnValue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float NextSpawnCoolDown = 2.0f;
	float SpawnCoolDown = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int cantSpawn = 5;

	UPROPERTY(VisibleAnywhere, Category = "Spawing")
		class UBoxComponent* WhereToSpawn;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TArray<TSubclassOf<AActor>> SpawnClasses;

};
