// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class UStaticMeshComponent;

UCLASS()
class LOSTPOTENTIAL_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
	public:	
		
		AMovingPlatform();
		virtual void Tick(float DeltaTime) override;

		UFUNCTION(BlueprintCallable)
		void SetCanMove(bool CanMove);

	private:
		UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Mesh;

		UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float MovementSpeed;

		UPROPERTY(EditAnywhere, Category = "Movement", meta = (MakeEditWidget = true))
		FVector TargetLocation;

		UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		bool bIsLooping;

		FVector InitialLocation;
		FVector EndLocation;
		bool bCanMove = true;

		void SwapLocations();


	protected:
		virtual void BeginPlay() override;
};
