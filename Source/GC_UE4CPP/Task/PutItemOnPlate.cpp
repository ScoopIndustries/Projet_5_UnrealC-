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
	auto plate = player->ListOfPoint[player->CycleIndex]->GetActorLocation();

	if ((player->GetActorLocation().X - plate.X) < 2000.0f)
	{
		//Detach Food component
		if (player->FoodActor != nullptr)
		{
			FDetachmentTransformRules rules(EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, false);
			player->FoodActor->DetachFromActor(rules);
			//Attach Food Component to Plate
			FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::SnapToTarget, false);
			player->FoodActor->AttachToActor(player->ListOfPoint[player->CycleIndex], Rules, TEXT("SocketApple"));
			player->FoodActor = nullptr;
		}
	}


	return EBTNodeResult::Succeeded;
}