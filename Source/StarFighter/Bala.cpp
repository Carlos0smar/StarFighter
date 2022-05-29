// Fill out your copyright notice in the Description page of Project Settings.


#include "Bala.h"
#include "NaveJugador.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


ABala::ABala()
{

   //ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
}

void ABala::BeginPlay()
{
	Super::BeginPlay();
}



void ABala::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

