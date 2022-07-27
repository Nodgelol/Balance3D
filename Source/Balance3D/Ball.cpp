// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABall::ABall()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Player Possession
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Creating Components
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm Component"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));

	// Attachments
	RootComponent = SceneComponent;
	StaticMesh->SetupAttachment(SceneComponent);
	SpringArm->SetupAttachment(StaticMesh);
	CameraComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// Setup Camera Settings
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 600.f;

	// Setup Ball Settings
	StaticMesh->SetSimulatePhysics(true);


	// Others
	MovementSpeed = 600.f;
}


// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setup KeyBindings
	PlayerInputComponent->BindAxis("MoveForward", this, &ABall::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABall::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ABall::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ABall::Turn);
}

void ABall::MoveForward(float value)
{
	// Movement
	FVector ForceVector = CameraComponent->GetForwardVector();
	ForceVector.X = ForceVector.X * value * MovementSpeed;
	ForceVector.Y = ForceVector.Y * value * MovementSpeed;
	FName BoneName = TEXT("None");
	StaticMesh->AddForce(ForceVector, BoneName, true);
}

void ABall::MoveRight(float value)
{
	// Movement
	FVector ForceVector = CameraComponent->GetRightVector();
	ForceVector.X = ForceVector.X * value * MovementSpeed;
	ForceVector.Y = ForceVector.Y * value * MovementSpeed;
	FName BoneName = TEXT("None");
	StaticMesh->AddForce(ForceVector, BoneName, true);
}

void ABall::LookUp(float value)
{
	// Camera Up and Down
	AddControllerPitchInput(value);
}

void ABall::Turn(float value)
{
	// Camera Left and Right
	AddControllerYawInput(value);
}

void ABall::Teleporte(FVector dahin)
{
	StaticMesh->SetWorldLocation(dahin);
}