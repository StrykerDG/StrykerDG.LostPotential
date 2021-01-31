#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "LostPotential/Actors/MovingPlatform.h"

APlatformTrigger::APlatformTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	SetRootComponent(BaseMesh);

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	ButtonMesh->SetupAttachment(BaseMesh);

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	TriggerVolume->SetupAttachment(BaseMesh);
}

void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	for (AMovingPlatform* Platform : ControlledPlatforms) 
		Platform->SetCanMove(false);

	if (TriggerVolume != nullptr)
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::BeginOverlap);
}

void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::BeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Firing..."));
	// TODO: Only work if it's the player
	for (AMovingPlatform* Platform : ControlledPlatforms)
		Platform->SetCanMove(true);
}