// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNaveEnemiga.h"
#include "NaveEnemigaBuilder.h"
#include "NaveEnemiga.h"
// Sets default values
ADirectorNaveEnemiga::ADirectorNaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void ADirectorNaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

ANaveEnemiga* ADirectorNaveEnemiga::GetNaveEnemiga()
{


	NaveEnemiga->MoveAhead = NaveEnemigaBuilder->BuildMoveAhead();


	return nullptr;
}
// Called every frame
void ADirectorNaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

