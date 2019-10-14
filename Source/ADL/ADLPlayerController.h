// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ADLPlayerController.generated.h"

UCLASS()
class AADLPlayerController : public APlayerController
{
   GENERATED_BODY()

public:
   AADLPlayerController();

protected:
   /** True if the controlled character should navigate to the mouse cursor. */
   uint32 bMoveToMouseCursor : 1;

   // Begin PlayerController interface
   void PlayerTick(float DeltaTime) override;
   void SetupInputComponent() override;
   // End PlayerController interface

   /** Resets HMD orientation in VR. */
   void OnResetVR();

   /** Navigate player to the current mouse cursor location. */
   void MoveToMouseCursor();

   /** Navigate player to the current touch location. */
   void MoveToTouchLocation(ETouchIndex::Type FingerIndex, FVector Location);

   /** Navigate player to the given world location. */
   void SetNewMoveDestination(FVector DestLocation);

   /** Input handlers for SetDestination action. */
   void OnSetDestinationPressed();
   void OnSetDestinationReleased();
};
