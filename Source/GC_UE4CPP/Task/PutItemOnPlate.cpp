// Fill out your copyright notice in the Description page of Project Settings.


#include "PutItemOnPlate.h"
#include "BBkey.h"
#include "../EnemyController.h"
#include "GC_UE4CPP/AI/AIBotCharacter.h"

UPutItemOnPlate::UPutItemOnPlate()
{
	NodeName = TEXT("Put On Plate");
}

EBTNodeResult::Type UPutItemOnPlate::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//Get Controller
	auto const controller = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	auto const enemy = controller->GetPawn();
	auto const player = Cast<AAIBotCharacter>(enemy);
	

	//Detach Food component
	if (player->FoodActor != nullptr)
	{
		FDetachmentTransformRules rules(EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, false);
		player->FoodActor->DetachFromActor(rules);
		player->FoodActor = nullptr;
	}

	player->ListOfPoint[0]->GetActorLocation();
	//Attach Food Component to Plate


	return EBTNodeResult::Succeeded;
}