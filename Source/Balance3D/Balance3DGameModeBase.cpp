// Copyright Epic Games, Inc. All Rights Reserved.


#include "Balance3DGameModeBase.h"
#include "PlayerBall.h"

void ABalance3DGameModeBase::ABalance3DGameMode()
{
	DefaultPawnClass = APlayerBall::StaticClass();
}
