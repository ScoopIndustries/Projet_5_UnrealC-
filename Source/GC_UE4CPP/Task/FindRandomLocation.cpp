// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "../EnemyController.h"
#include "Math/UnrealMathUtility.h"
#include "GC_UE4CPP/AI/AIBotCharacter.h"
#include "Blackboard_Keys.h"

UFindRandomLocation::UFindRandomLocation(FObjectInitializer const& Object_Initializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory)
{
	//Get AI Controller
	auto const controller = Cast<AEnemyController>(Owner_Component.GetAIOwner());
	auto const enemy = controller->GetPawn();
	auto const player = Cast<AAIBotCharacter>(enemy);

	INT8 Index = FMath::RandRange(0, 4);

	FVector location = player->ListOfPoint[Index]->GetActorLocation();
	controller->GetBlackboard()->SetValueAsVector(bb_keys::Target_Location, location);
	controller->GetBlackboard()->SetValueAsInt(bb_keys::IndexListPlate, Index);

	//Finish with success
	return EBTNodeResult::Succeeded;
}
