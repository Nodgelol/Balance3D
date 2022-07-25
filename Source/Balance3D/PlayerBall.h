// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBall.generated.h"

UCLASS()
class BALANCE3D_API APlayerBall : public ACharacter
{
	GENERATED_BODY()

	/** StaticMesh used for the ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Ball;

	/** Spring arm for positioning the camera above the ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	/** Camera to view the ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

public:
	// Sets default values for this character's properties
	APlayerBall();

	/** Vertical impulse to apply when pressing jump */
	UPROPERTY(EditAnywhere, Category = Ball)
		float JumpImpulse;

	/** Torque to apply when trying to roll ball */
	UPROPERTY(EditAnywhere, Category = Ball)
		float RollTorque;

	/** Indicates whether we can currently jump, use to prevent double jumping */
	bool bCanJump;
	bool bDead;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Called to move ball forwards and backwards */
	void MoveForward(float Val);

	/** Called to look up and down */
	void LookUp(float val);

	/** Called to look left and right */
	void Lookright(float val);

	/** Handle jump action. */
	void Jump();

	// AActor interface
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	// End of AActor interface

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Ball subobject **/
	FORCEINLINE class UStaticMeshComponent* GetBall() const { return Ball; }
	/** Returns SpringArm subobject **/
	FORCEINLINE class USpringArmComponent* GetSpringArm() const { return SpringArm; }
	/** Returns Camera subobject **/
	FORCEINLINE class UCameraComponent* GetCamera() const { return Camera; }
};
