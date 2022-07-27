// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedUpBox.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

ASpeedUpBox::ASpeedUpBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ASpeedUpBox::EnterSpeedUpBox);
	OnActorEndOverlap.AddDynamic(this, &ASpeedUpBox::ExitSpeedUpBox);
	
	speeding = false;
}

void ASpeedUpBox::BeginPlay()
{
	Super::BeginPlay();
}

void ASpeedUpBox::EnterSpeedUpBox(class AActor* overlappedActor, class AActor* otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapping"));
	if (otherActor && otherActor != this)
	{
		ABall* character = Cast<ABall>(otherActor);
		speeding = true;
		UGameplayStatics::PlaySoundAtLocation(this, dbzSpeed, this->GetActorLocation());
		character->StaticMesh->AddImpulse(FVector(0.f, 0.f, 1000.f));
	}
}

void ASpeedUpBox::ExitSpeedUpBox(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (this && !speeding)
		{
			this->speeding = false;
		}
	}
}
