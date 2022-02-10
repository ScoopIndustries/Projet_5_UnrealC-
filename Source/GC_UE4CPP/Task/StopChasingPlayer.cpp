// Fill out your copyright notice in the Description page of Project Settings.


#include "StopChasingPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../EnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "BBKey.h"

UStopChasingPlayer::UStopChasingPlayer(FObjectInitializer const& object_initializer) {
	NodeName = TEXT("Stop Chasing Player");
}

EBTNodeResult::Type UStopChasingPlayer::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) {
	auto const cont = Cast<AEnemyController>(owner_comp.GetAIOwner());

	cont->GetBlackboard()->SetValueAsBool(BBKeys::PlayerDetected, false);

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Type();
}

