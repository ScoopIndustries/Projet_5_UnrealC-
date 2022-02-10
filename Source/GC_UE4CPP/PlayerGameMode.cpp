// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ScoreWidget.h"
#include "AI/Waypoint.h"
#include "WinMenuWidget.h"
#include "LoseMenuWidget.h"
#include "MainMenuWidget.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/UObjectGlobals.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "EnemyController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Blueprint\UserWidget.h"

void APlayerGameMode::BeginPlay()
{
	Super::BeginPlay();

	//Get All actor Needs to place food
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), ListOfPoint);

	FTimerHandle SpawnTimer;
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APlayerGameMode::SpawnEnemy, 20.0f, true);
	if (IsValid(ScoreWidgetClass))
	{
		ScoreWidget = Cast<UScoreWidget>(CreateWidget(GetWorld(), ScoreWidgetClass));
		WinWidget = Cast<UWinMenuWidget>(CreateWidget(GetWorld(), WinWidgetClass));
		LoseWidget = Cast<ULoseMenuWidget>(CreateWidget(GetWorld(), LoseWidgetClass));
		MainMenuWidget = Cast<UMainMenuWidget>(CreateWidget(GetWorld(), MainMenuWidgetClass));

		if (MainMenuWidget != nullptr)
		{
			MainMenuWidget->AddToViewport();
		}
	}
}


void APlayerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerGameMode::SpawnEnemy()
{
	FActorSpawnParameters SpawnInfo;
	auto ActorAI = GetWorld()->SpawnActor<AAIBotCharacter>(AIBotClass, FVector(580, 3240, 0), FRotator(0), SpawnInfo);
	auto ActorAII = GetWorld()->SpawnActor<AAIBotCharacter>(AIBotClass, FVector(580, 3240, 0), FRotator(0), SpawnInfo);
	auto cast = Cast<AEnemyController>(ActorAII->GetOwner());
	cast->GetBlackboard()->SetValueAsBool(TEXT("HaveFood"), false);
	cast->GetBlackboard()->SetValueAsBool(TEXT("IsPatrolling"), true);
}

void APlayerGameMode::GameWin()
{
	ScoreWidget->RemoveFromViewport();

	if (WinWidget != nullptr)
	{
		WinWidget->AddToViewport();

	}
}

void APlayerGameMode::GameLost()
{
	ScoreWidget->RemoveFromViewport();

	if (LoseWidget != nullptr)
	{
		LoseWidget->AddToViewport();
	}
}

void APlayerGameMode::StartGame()
{
	UGameplayStatics::GetPlayerController(this, 0)->SetShowMouseCursor(false);

	MainMenuWidget->RemoveFromViewport();
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	if (ScoreWidget != nullptr)
	{
		ScoreWidget->AddToViewport();
	}
}