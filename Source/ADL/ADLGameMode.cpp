// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ADLGameMode.h"
#include "ADLPlayerController.h"
#include "ADLCharacter.h"
#include "UObject/ConstructorHelpers.h"

AADLGameMode::AADLGameMode()
{
   // use our custom PlayerController class
   PlayerControllerClass = AADLPlayerController::StaticClass();

   // set default pawn class to our Blueprinted character
   static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
      TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
   if (PlayerPawnBPClass.Class != nullptr)
   {
      DefaultPawnClass = PlayerPawnBPClass.Class;
   }
}
