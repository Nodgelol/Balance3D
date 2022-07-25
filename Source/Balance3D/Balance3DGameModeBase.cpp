// Copyright Epic Games, Inc. All Rights Reserved.


#include "Balance3DGameModeBase.h"
#include "PlayerBall.h"

ABalance3DGameMode::ABalance3DGameMode()
{
	// set default pawn class to our ball
	DefaultPawnClass = APlayerBall::StaticClass();
}
