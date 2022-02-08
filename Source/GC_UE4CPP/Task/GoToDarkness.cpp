// Fill out your copyright notice in the Description page of Project Settings.


#include "GoToDarkness.h"
#include "../EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/AIBotCharacter.h"
#include "Blackboard_Keys.h"

UGoToDarkness::UGoToDarkness(FObjectInitializer const& Object_Initializer)
{
	NodeName = TEXT("Go To Darkness");
}

EBTNodeResult::Type UGoToDarkness::ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory)
{
	auto const controller = Cast<AEnemyController>(Owner_Component.GetAIOwner());
	auto const enemy = controller->GetPawn();
	auto const player = Cast<AAIBotCharacter>(enemy);

	player->Destroy();

	return EBTNodeResult::Succeeded;
}