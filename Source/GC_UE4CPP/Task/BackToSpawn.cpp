// Fill out your copyright notice in the Description page of Project Settings.


#include "BackToSpawn.h"
#include "../EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/AIBotCharacter.h"
#include "Blackboard_Keys.h"

UBackToSpawn::UBackToSpawn(FObjectInitializer const& Object_Initializer)
{
	NodeName = TEXT("Back To Spawn");
}

EBTNodeResult::Type UBackToSpawn::ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory)
{
	auto const controller = Cast<AEnemyController>(Owner_Component.GetAIOwner());
	auto const enemy = controller->GetPawn();
	auto const player = Cast<AAIBotCharacter>(enemy);

	FVector location = FVector(0, 0, 0);
	controller->GetBlackboard()->SetValueAsVector(bb_keys::Target_Location, location);

	return EBTNodeResult::Succeeded;
}