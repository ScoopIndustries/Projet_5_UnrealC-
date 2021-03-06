// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFrameWork/Pawn.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UObjectGlobals.h"
#include "FindPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UFindPatrolLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UFindPatrolLocation(FObjectInitializer const& object_initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

private:
	UPROPERTY(EditAnywhere)
		float search_radius = 3000.0f;
};
