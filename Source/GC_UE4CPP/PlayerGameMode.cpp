// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ScoreWidget.h"
#include "AI/Waypoint.h"
#include "WinMenuWidget.h"
#include "LoseMenuWidget.h"
#include "MainMenuWidget.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Blueprint\UserWidget.h"

void APlayerGameMode::BeginPlay()
{
	Super::BeginPlay();

	//Get All actor Needs to place food
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), ListOfPoint);

	FTimerHandle SpawnTimer;
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &APlayerGameMode::SpawnEnemy, 10.0f, true);
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
	//auto ActorAII = GetWorld()->SpawnActor<AAIBotCharacter>(AIBotClass, FVector(580, 3240, 0), FRotator(0), SpawnInfo);
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