// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "Ball.h"
#include "GameFramework/SpringArmComponent.h"
#include "SpeedUpBox.generated.h"


UCLASS()
class BALANCE3D_API ASpeedUpBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Sound")
		class USoundBase* dbzSpeed;

public:
	ASpeedUpBox();

	UFUNCTION()
		void EnterSpeedUpBox(class AActor* overlappedActor, class AActor* otherActor);

	UFUNCTION()
		void ExitSpeedUpBox(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY()
		bool speeding;

};
