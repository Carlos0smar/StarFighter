// Copyright Epic Games, Inc. All Rights Reserved.


#include "SpawnCapsulaArmamento.h"
#include "SpawnCapsulaVida.h"
#include "SpawnCapsulaEnergia.h"
#include "StarFighterGameModeBase.h"
#include "Capsula.h"
#include "NaveJugador.h"

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = ANaveJugador::StaticClass();
}

void AStarFighterGameModeBase::Tick(float DeltaTime)		
{
	Super::Tick(DeltaTime);

	float ProbabilidadAparicionCapsula = FMath::RandRange(0, 10000);

	if (ProbabilidadAparicionCapsula < 100.0f) {

		//Create the Shops
		ASpawnCapsula* SpawnCapsulaVida= GetWorld()->SpawnActor<ASpawnCapsulaVida>(ASpawnCapsulaVida::StaticClass());
		ACapsula* Capsula = SpawnCapsulaVida->GetCapsula("Vida");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetCapsulaName()));

	}
	else if (ProbabilidadAparicionCapsula > 5.0f && ProbabilidadAparicionCapsula < 10.0f) {

		//Create the Shopsn 
		ASpawnCapsula* SpawnCapsulaEnegia = GetWorld()->SpawnActor<ASpawnCapsulaEnergia>(ASpawnCapsulaEnergia::StaticClass());
		ACapsula* Capsula = SpawnCapsulaEnegia->GetCapsula("Energia");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetCapsulaName()));

	}
	else if (ProbabilidadAparicionCapsula > 10.0f && ProbabilidadAparicionCapsula < 12.0f) {

		//Create the Shops
		ASpawnCapsula* SpawnCapsulaArmamento = GetWorld()->SpawnActor<ASpawnCapsulaArmamento>(ASpawnCapsulaArmamento::StaticClass());
		ACapsula* Capsula = SpawnCapsulaArmamento->GetCapsula("Armamento");
		//GeneradorCapsulaArma = GetWorld()->SpawnActor<AGeneradorCapsulasEnergia>(AGeneradorCapsulasEnergia::StaticClass());
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Turquoise, FString::Printf(TEXT("Capsula generada %s"), *Capsula->GetCapsulaName()));

	}
}

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Dentro de BeginPlay")));
}
