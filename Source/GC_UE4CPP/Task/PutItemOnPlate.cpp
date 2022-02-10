// Fill out your copyright notice in the Description page of Project Settings.


#include "PutItemOnPlate.h"
#include "BBkey.h"
#include "../EnemyController.h"
#include "../AI/Waypoint.h"
#include "../PlayerGameMode.h"
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
	auto GameMode = GetWorld()->GetAuthGameMode();
	auto CastGM = Cast<APlayerGameMode>(GameMode);

	auto const Index = controller->GetBlackboard()->GetValueAsInt(TEXT("IndexListPlate"));
	auto HaveFood = controller->GetBlackboard()->GetValueAsBool(TEXT("HaveFood"));
	auto plate = CastGM->ListOfPoint[Index];
	auto const CastPlate = Cast<AWaypoint>(plate);

	if ((player->GetActorLocation().X - plate->GetActorLocation().X) < 600.0f && CastPlate->Food == nullptr && player->FoodActor != nullptr)
	{
			FDetachmentTransformRules rules(EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, EDetachmentRule::KeepRelative, false);
			player->FoodActor->DetachFromActor(rules);
			//Attach Food Component to Plate
			FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::SnapToTarget, false);
			player->FoodActor->AttachToActor(plate, Rules, TEXT("SocketApple"));
			CastPlate->Food = player->FoodActor;
			player->FoodActor = nullptr;
			controller->GetBlackboard()->SetValueAsBool(TEXT("HaveFood"), false);
			return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}