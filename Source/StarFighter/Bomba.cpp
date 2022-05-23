// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"

#include "NaveJugador.h"

ABomba::ABomba()
{

}

void ABomba::BeginPlay()
{
	Super::BeginPlay();
}

void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABomba::NotifyActorBeginOverlap(AActor* OtherActor)
{
    UE_LOG(LogTemp, Warning, TEXT("collect with %s"), *OtherActor->GetFName().ToString());
    ANaveJugador* player = Cast<ANaveJugador>(OtherActor);
    if (player)
    {
        player->Destroy();
        this->Destroy();
    }
}
