// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "EnemyCharacter.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Task/BBKey.h"


AEnemyController::AEnemyController(FObjectInitializer const& ObjectInitializer = FObjectInitializer::Get()) {

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/William/BT_Bots.BT_Bots'"));
	if (obj.Succeeded())
	{
		BTree = obj.Object;
	}
	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComponent"));
	blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));

	PrimaryActorTick.bCanEverTick = true;
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AEnemyController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

UBlackboardComponent* AEnemyController::GetBlackboard() const
{
	return blackboard;
}

void AEnemyController::BeginPlay() {
	Super::BeginPlay();
	RunBehaviorTree(BTree);
	BehaviorTreeComponent->StartTree(*BTree);
}

void AEnemyController::OnPossess(APawn *MyPawn) {
	Super::OnPossess(MyPawn);
	if (blackboard)
	{
		blackboard->InitializeBlackboard(*BTree->BlackboardAsset);
	}
}

void AEnemyController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}

FRotator AEnemyController::GetControlRotation() const {
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AEnemyController::OnPawnDetected(const TArray<AActor*> &DetectedPawns) {

	blackboard->SetValueAsBool(BBKeys::PlayerDetected, true);
}