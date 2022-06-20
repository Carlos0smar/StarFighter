// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capsula.h"
#include "GameFramework/Actor.h"
#include "SpawnCapsula.generated.h"

UCLASS()
class STARFIGHTER_API ASpawnCapsula : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnCapsula();

	UPROPERTY(VisibleAnywhere, Category = "Spawing")
	class UBoxComponent* WhereToSpawn;

	virtual ACapsula* FabricarCapsula(FString NombreTipoCapsula) PURE_VIRTUAL(ASpawnCapsula::FabricarCapsula, return nullptr;);

	ACapsula* GetCapsula(FString TipoCapsula);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
