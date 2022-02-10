// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AI/AIBotCharacter.h"
#include "EnemyController.h"
#include "AI/Waypoint.h"
#include "PlayerCharacter.h"
#include "PlayerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API APlayerGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	float GetMaxFoodConditionWin() const { return MaxFoodConditionWin; }
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void GameWin();
	UFUNCTION()
		void GameLost();
	UFUNCTION()
		void StartGame();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class AFood> FoodClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<AActor*> ListOfPoint;

protected:
	virtual void BeginPlay() override;
	void SpawnEnemy();

	UPROPERTY(EditAnywhere)
		float MaxFoodConditionWin = 5.f;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> ScoreWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> WinWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> LoseWidgetClass;
	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UScoreWidget* ScoreWidget;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UWinMenuWidget* WinWidget;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class ULoseMenuWidget* LoseWidget;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UMainMenuWidget* MainMenuWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAIBotCharacter> AIBotClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AEnemyController> EnemyController;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerCharacter* PlayerCharacter;


};
