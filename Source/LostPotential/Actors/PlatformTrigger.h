// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

class AMovingPlatform;
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class LOSTPOTENTIAL_API APlatformTrigger : public AActor
{
	GENERATED_BODY()
	
	public:	
		APlatformTrigger();
		virtual void Tick(float DeltaTime) override;

	private:
		UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMesh;
		UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ButtonMesh;
		UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* TriggerVolume;

		UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
		TArray<AMovingPlatform*> ControlledPlatforms;

		UFUNCTION()
			void BeginOverlap(
				UPrimitiveComponent* OverlappedComponent,
				AActor* OtherActor,
				UPrimitiveComponent* OtherComp,
				int32 OtherBodyIndex,
				bool bFromSweep,
				const FHitResult& SweepResult
			);

	protected:
		virtual void BeginPlay() override;

};
