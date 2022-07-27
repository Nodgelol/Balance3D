#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "Ball.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyTeleporterBox.generated.h"


	UCLASS()
	class BALANCE3D_API AMyTeleporterBox : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AMyTeleporterBox();

	UFUNCTION()
		void EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor);

	UFUNCTION()
		void ExitTeleporter(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY(EditAnywhere, Category = "Teleporter")
		AMyTeleporterBox* otherTele;

	UPROPERTY()
		bool teleporting;

	
		


};