// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTeleporterBox.h"


AMyTeleporterBox::AMyTeleporterBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyTeleporterBox::EnterTeleporter);
	OnActorEndOverlap.AddDynamic(this, &AMyTeleporterBox::ExitTeleporter);
	teleporting = false;

}

void AMyTeleporterBox::BeginPlay()
{

	Super::BeginPlay();

}

void AMyTeleporterBox::EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherTele)
		{

			ABall* character = Cast<ABall>(otherActor);
			if (character && !otherTele->teleporting)
			{
				teleporting = true;

				character->Teleporte(otherTele->GetActorLocation());

			}
		}
	}
}

void AMyTeleporterBox::ExitTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherTele && !teleporting)
		{
			otherTele->teleporting = false;
		}
	}
}