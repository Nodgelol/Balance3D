// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball.generated.h"

UCLASS()
class BALANCE3D_API ABall : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool jumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpImpulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementSpeed;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void Turn(float value);
	void Jump();
	void StopJump();
	void Teleporte(FVector value);
};
