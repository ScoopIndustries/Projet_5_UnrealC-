// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Waypoint.h"
#include "AIBotController.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAIBotController : public AAIController
{
	GENERATED_BODY()
	
public:

	AAIBotController();

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* Pawn) override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
	TArray<AWaypoint*> ListOfPlates;
};
