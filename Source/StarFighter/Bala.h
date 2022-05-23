// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Bala.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ABala : public AProyectil
{
	GENERATED_BODY()
	
public:
	ABala();


//	UPROPERTY(VisibleAnywhere, Category = "Component")
//		UProjectileMovementComponent* ProjectileMovementComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
