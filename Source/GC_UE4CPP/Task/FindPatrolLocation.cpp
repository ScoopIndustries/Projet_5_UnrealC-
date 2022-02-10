// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPatrolLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "../EnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BBKey.h"

UFindPatrolLocation::UFindPatrolLocation(FObjectInitializer const& object_initializer) {
	NodeName = TEXT("Find Patrol Location");
}

EBTNodeResult::Type UFindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) {
	auto const cont = Cast<AEnemyController>(owner_comp.GetAIOwner());
	auto const npc = cont->GetPawn();

	FVector const origin = npc->GetActorLocation();
	FNavLocation loc;

	UNavigationSystemV1* const nav_sys = UNavigationSystemV1::GetCurrent(GetWorld());

	if (nav_sys->GetRandomPointInNavigableRadius(origin, search_radius, loc, nullptr)) {
		cont->GetBlackboard()->SetValueAsVector(BBKeys::TargetLocation, loc.Location);
	}

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Type();
}
