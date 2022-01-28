// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn *Pawn) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation()const override;

	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(VisibleAnywhere, Category = AI)
		float AISightRadius = 500;

	UPROPERTY(VisibleAnywhere, Category = AI)
		float AISightAge = 5.0f;

	UPROPERTY(VisibleAnywhere, Category = AI)
		float AILoseSightRadius = AISightRadius + 50.0f;

	UPROPERTY(VisibleAnywhere, Category = AI)
		float AIFieldOfView = 67.5f;

	UPROPERTY(VisibleAnywhere, Category = AI)
		class UAISenseConfig_Sight *SightConfig;

	UPROPERTY(VisibleAnywhere, Category = AI)
		bool bIsPlayerDetected = false;

	UPROPERTY(VisibleAnywhere, Category = AI)
		float DistanceToPlayer = 0.0f;

/*private:
	FVector lastKnowPosition;*/
};