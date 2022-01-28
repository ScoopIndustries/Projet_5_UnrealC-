// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
//#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Blackboard_Keys.h"
#include "AIC_NPController.h"

UFindRandomLocation::UFindRandomLocation(FObjectInitializer const& Object_Initializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory)
{
	//Get AI Controller
	auto const controller = Cast<AAIC_NPController>(Owner_Component.GetAIOwner());
	auto const npc = controller->GetPawn();

	//Obtain NPC Location to use Origin
	FVector const origin = npc->GetActorLocation();
	FNavLocation location;

	//Get NavMeshSystem and generate random location
	UNavigationSystemV1* const NavMeshSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavMeshSystem->GetRandomPointInNavigableRadius(origin, SearchRadius, location, nullptr))
	{
		controller->Get_Blackboard()->SetValueAsVector(bb_keys::Target_Location, location.Location);
	}

	//Finish with success
	FinishLatentTask(Owner_Component, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
