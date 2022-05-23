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

/*void ABala::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);

    UE_LOG(LogTemp, Warning, TEXT("collect with %s"), *OtherActor->GetFName().ToString());
    ANaveJugador* player = Cast<ANaveJugador>(OtherActor);
    if (player)
    {
        player->Destroy();
        this->Destroy();
    }
}*/
