// Fill out your copyright notice in the Description page of Project Settings.


#include "LetOnGround.h"
#include "../EnemyController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GC_UE4CPP/AI/AIBotCharacter.h"

ULetOnGround::ULetOnGround(FObjectInitializer const& Object_Initializer)
{
	NodeName = TEXT("Let On Ground");
}

EBTNodeResult::Type ULetOnGround::ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory)
{
	auto const controller = Cast<AEnemyController>(Owner_Component.GetAIOwner());
	auto const enemy = controller->GetPawn();
	auto const player = Cast<AAIBotCharacter>(enemy);

	FDetachmentTransformRules rules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepRelative, EDetachmentRule::KeepWorld, false);
	player->FoodActor->DetachFromActor(rules);
	player->isCarrying = false;

	return EBTNodeResult::Succeeded;

}