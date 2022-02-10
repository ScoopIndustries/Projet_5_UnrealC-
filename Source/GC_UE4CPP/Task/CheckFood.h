// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "CheckFood.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API UCheckFood : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UCheckFood(FObjectInitializer const& Object_Initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory);
};
