// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/UObjectGlobals.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "PutItemOnPlate.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GC_UE4CPP_API UPutItemOnPlate : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UPutItemOnPlate();
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);


};
