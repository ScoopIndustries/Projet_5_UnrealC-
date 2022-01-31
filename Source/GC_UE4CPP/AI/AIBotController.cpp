// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBotController.h"
#include "AIBotCharacter.h"
#include "Waypoint.h"

AAIBotController::AAIBotController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAIBotController::BeginPlay()
{
	Super::BeginPlay();
}

void AAIBotController::OnPossess(APawn* APawn)
{
	Super::OnPossess(APawn);
}

void AAIBotController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AAIBotCharacter* Chara = Cast<AAIBotCharacter>(GetPawn());
	if (Chara->NextWaypoint != nullptr)
	{
		MoveToActor(Chara->NextWaypoint, 5.0f);
	}

}
