// Copyright Epic Games, Inc. All Rights Reserved.

#include "FreeMultiplayerGameMode.h"
#include "Character/FMCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFreeMultiplayerGameMode::AFreeMultiplayerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Blueprints/Player/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
