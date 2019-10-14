// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "UObjectIterator.h"

AMyPawn::AMyPawn()
{
   PrimaryActorTick.bCanEverTick = true;

   // Setup Actor Ref
   /*SplineRef = PathActorRef->GetComponentByClass(USplineComponent);*/

   // Setup the path buffer
   // 
   for (TObjectIterator<USplineComponent> SplineComponent; SplineComponent; ++ SplineComponent)
   {
      const int NumberOfSplinePoints = SplineComponent->GetNumberOfSplinePoints();
      const float TotalLength = SplineComponent->GetSplineLength();

      float CurrentLength = 0;

      if (NumberOfSplinePoints > 5)
      {
         size_t SplinePointCount = 0;

         while (CurrentLength < TotalLength)
         {
            // The next line samples the spline at "currentLength" units from the starting point
            auto SplinePointTransform = SplineComponent->GetTransformAtDistanceAlongSpline(
               CurrentLength, ESplineCoordinateSpace::World);

            CurrentLength += SampleLength;

            PathPointRotation[SplinePointCount] = SplinePointTransform.GetRotation();
            PathPointLocation[SplinePointCount] = SplinePointTransform.GetLocation();

            ++SplinePointCount;
         }

         TotalSplinePoints = SplinePointCount;
      }
   }
}

void AMyPawn::BeginPlay()
{
   Super::BeginPlay();
}

void AMyPawn::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   // Update Location & Rotations
   RootComponent->SetWorldLocation(PathPointLocation[SplinePointer]);
   RootComponent->SetWorldRotation(PathPointRotation[SplinePointer]);

   // Update counter
   ++SplinePointer;
   if (SplinePointer >= TotalSplinePoints)
   {
      SplinePointer = 0;
   }
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
   Super::SetupPlayerInputComponent(PlayerInputComponent);
}
