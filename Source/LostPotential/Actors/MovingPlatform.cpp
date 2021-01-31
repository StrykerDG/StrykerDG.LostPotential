#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	//Mesh->SetupAttachment(RootComponent);

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
	EndLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCanMove) 
	{
		FVector CurrentLocation = GetActorLocation();
		float DistanceBetweenLocations = (EndLocation - InitialLocation).Size();
		float DistanceTraveled = (CurrentLocation - InitialLocation).Size();

		if (DistanceTraveled >= DistanceBetweenLocations && bIsLooping)
		{
			SwapLocations();
		}
		else if (DistanceTraveled >= DistanceBetweenLocations && !bIsLooping)
		{
			bCanMove = false;
		}

		FVector MovementVector = (EndLocation - InitialLocation).GetSafeNormal();
		CurrentLocation += MovementVector * MovementSpeed * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::SwapLocations() 
{
	FVector temp = InitialLocation;
	InitialLocation = EndLocation;
	EndLocation = temp;
}

void AMovingPlatform::SetCanMove(bool CanMove)
{
	bCanMove = CanMove;
}