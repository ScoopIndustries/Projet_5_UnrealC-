// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "EnemyCharacter.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AEnemyController::AEnemyController() {
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

void AEnemyController::BeginPlay() {
	Super::BeginPlay();
}

void AEnemyController::OnPossess(APawn *MyPawn) {
	Super::OnPossess(MyPawn);
}

void AEnemyController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(GetPawn());

	if (DistanceToPlayer > AISightRadius) {
		bIsPlayerDetected = false;
	}

	if (bIsPlayerDetected == false) {
		MoveToActor(Enemy->Target);
	}
	else{
		ATP_ThirdPersonCharacter* Player = Cast<ATP_ThirdPersonCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		MoveToActor(Player, 5.0f);
		//MoveTo(lastKnowPosition);

	}
}

FRotator AEnemyController::GetControlRotation() const {
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AEnemyController::OnPawnDetected(const TArray<AActor*> &DetectedPawns) {

	for (size_t i = 0; i < DetectedPawns.Num(); i++) {
		DistanceToPlayer = GetPawn()->GetDistanceTo(DetectedPawns[i]);
		//lastKnowPosition = DetectedPawns[i]->GetActorLocation();
	}

	bIsPlayerDetected = true;


}