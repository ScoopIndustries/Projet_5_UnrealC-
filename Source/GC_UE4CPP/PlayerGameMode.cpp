// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ScoreWidget.h"
#include "Blueprint\UserWidget.h"

void APlayerGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle SpawnTimer;
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APlayerGameMode::SpawnEnemy, 10.0f, false);
	if (IsValid(WidgetClass))
	{
		ScoreWidget = Cast<UScoreWidget>(CreateWidget(GetWorld(), WidgetClass));

		if (ScoreWidget != nullptr)
		{
			ScoreWidget->AddToViewport();
		}
	}
}


void APlayerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool IsStarted = false;

	if (IsStarted == false)
	{
		FTimerHandle SpawnTimer;
		GetWorldTimerManager().SetTimer(SpawnTimer, this, &APlayerGameMode::SpawnEnemy, 10.0f, false);
		IsStarted = true;
	}

}

void APlayerGameMode::SpawnEnemy()
{
	FActorSpawnParameters SpawnInfo;
	auto ActorAI = GetWorld()->SpawnActor<AAIBotCharacter>(AIBotClass, FVector(580, 3240, 0), FRotator(0), SpawnInfo);
	auto ControllerAI = GetWorld()->SpawnActor<AEnemyController>(EnemyController, FVector(580, 3240, 0), FRotator(0), SpawnInfo);
	FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	ControllerAI->AttachToActor(ActorAI, Rules);
}