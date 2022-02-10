// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckFood.h"
#include "../AI/AIBotCharacter.h"
#include "../EnemyController.h"
#include "../AI/Waypoint.h"
#include "../PlayerGameMode.h"
#include "Engine/Engine.h"

UCheckFood::UCheckFood(FObjectInitializer const& Object_Initializer)
{
	NodeName = TEXT("Check Food");
}

EBTNodeResult::Type UCheckFood::ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory)
{
	auto const controller = Cast<AEnemyController>(Owner_Component.GetAIOwner());
	auto const enemy = controller->GetPawn();
	auto const player = Cast<AAIBotCharacter>(enemy);
	auto GameMode = GetWorld()->GetAuthGameMode();
	auto CastGM = Cast<APlayerGameMode>(GameMode);
	int FoodInWorld = 0;

	for (int i = 0; i < 4; i++)
	{
		auto result = Cast<AWaypoint>(CastGM->ListOfPoint[i]);
		if (result->Food != nullptr)
		{
			FoodInWorld++;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("%FoodInWorld"));
	return EBTNodeResult::Succeeded;
}