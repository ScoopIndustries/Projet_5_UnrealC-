// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_NPController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"


AAIC_NPController::AAIC_NPController(FObjectInitializer const& Object_Initializer)
{
    static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/William/BT_Bots.BT_Bots'"));
    if (obj.Succeeded()) {
        BTree = obj.Object;
    }
    Behavior_Tree_Component = Object_Initializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComponent"));
    blackboard = Object_Initializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComponent"));
}


void AAIC_NPController::BeginPlay()
{
    Super::BeginPlay();
    RunBehaviorTree(BTree);
    Behavior_Tree_Component->StartTree(*BTree);
}

void AAIC_NPController::OnPossess(APawn* const pawn)
{
    Super::OnPossess(pawn);

    if (blackboard) {
        blackboard->InitializeBlackboard(*BTree->BlackboardAsset);
    }
}

UBlackboardComponent* AAIC_NPController::Get_Blackboard() const
{
    return blackboard;
}

