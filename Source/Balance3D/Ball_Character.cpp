// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball_Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ABall_Character::ABall_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Creating Components
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Springarm Component"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));

	// Attachments
	RootComponent = Capsule;
	StaticMesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(StaticMesh);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	// Setup Camera Settings
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 600.f;

	// Setup Ball Settings
	Capsule->InitCapsuleSize(50.f, 50.f);
	StaticMesh->SetSimulatePhysics(true);

	// Others
	jumping = false;
	JumpImpulse = 5000.f;
	MovementSpeed = 500.f;
}

// Called when the game starts or when spawned
void ABall_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (jumping)
	{
		Jump();
	}
}

// Called to bind functionality to input
void ABall_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Setup KeyBindings
	PlayerInputComponent->BindAxis("MoveForward", this, &ABall_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABall_Character::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ABall_Character::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ABall_Character::Turn);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABall_Character::CheckJump);
}

void ABall_Character::MoveForward(float value)
{
	// Movement
	FVector ForceVector = Camera->GetForwardVector();
	ForceVector.X = ForceVector.X * value * MovementSpeed;
	ForceVector.Y = ForceVector.Y * value * MovementSpeed;
	FName BoneName = TEXT("None");
	StaticMesh->AddForce(ForceVector, BoneName, true);
}

void ABall_Character::MoveRight(float value)
{
	// Movement
	FVector ForceVector = Camera->GetRightVector();
	ForceVector.X = ForceVector.X * value * MovementSpeed;
	ForceVector.Y = ForceVector.Y * value * MovementSpeed;
	FName BoneName = TEXT("None");
	StaticMesh->AddForce(ForceVector, BoneName, true);
}

void ABall_Character::LookUp(float value)
{
	// Camera Up and Down
	AddControllerPitchInput(value);
}

void ABall_Character::Turn(float value)
{
	// Camera Left and Right
	AddControllerYawInput(value);
}

void ABall_Character::Jump()
{
	// Jump
	const FVector Impulse = FVector(0.f, 0.f, JumpImpulse);
	FName BoneName = TEXT("None");
	StaticMesh->AddImpulse(Impulse);
}

void ABall_Character::CheckJump()
{
	if (jumping)
	{
		jumping = false;
	}
	else
	{
		jumping = true;
	}
}