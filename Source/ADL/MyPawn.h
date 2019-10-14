// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SplineComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class ADL_API AMyPawn : public APawn
{
   GENERATED_BODY()

public:
   // Sets default values for this pawn's properties
   AMyPawn();

protected:
   // Called when the game starts or when spawned
   void BeginPlay() override;

   UPROPERTY(EditAnywhere, Category = "Path Following")
   AActor* PathActorRef;

   UPROPERTY(EditAnywhere, Category = "Path Following")
   int SampleLength = 5;

public:
   // Called every frame
   void Tick(float DeltaTime) override;

   // Called to bind functionality to input
   void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

   // TODO: Fix me
   FVector PathPointLocation[500];
   FQuat PathPointRotation[500];
   size_t SplinePointer = 0;
   size_t TotalSplinePoints = 0;
};
