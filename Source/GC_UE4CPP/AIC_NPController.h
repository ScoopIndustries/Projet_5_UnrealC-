// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIC_NPController.generated.h"


/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AAIC_NPController : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIC_NPController(FObjectInitializer const& Object_Initializer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
	class UBlackboardComponent* Get_Blackboard() const;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* Behavior_Tree_Component;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BTree;

	class UBlackboardComponent* blackboard;
};
