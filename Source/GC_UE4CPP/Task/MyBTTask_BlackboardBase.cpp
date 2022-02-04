// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "../EnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BBkey.h"

UMyBTTask_BlackboardBase::UMyBTTask_BlackboardBase(FObjectInitializer const& ObjInit)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UMyBTTask_BlackboardBase::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get AIController ans its BOT ?
	auto const cont = Cast<AEnemyController>(OwnerComp.GetAIOwner());
	auto const npc = cont->GetPawn();

	FVector const origin = npc->GetActorLocation();
	FNavLocation loc;

	UNavigationSystemV1* const NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavSystem->GetRandomPointInNavigableRadius(origin, SearchRadius, loc, nullptr))
	{
		cont->GetBlackboard()->SetValueAsVector(BBKeys::TargetLocation, loc.Location);
	}

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}


