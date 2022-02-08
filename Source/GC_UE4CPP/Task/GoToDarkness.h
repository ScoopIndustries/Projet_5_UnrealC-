// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GoToDarkness.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UGoToDarkness : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UGoToDarkness(FObjectInitializer const& Object_Initializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Owner_Component, uint8* Node_Memory);
};
