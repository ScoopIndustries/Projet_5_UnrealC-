// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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

	UFUNCTION()
		void GameWin();
	UFUNCTION()
		void GameLost();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		float MaxFoodConditionWin = 5.f;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> ScoreWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> WinWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> LoseWidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UScoreWidget* ScoreWidget;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UWinMenuWidget* WinWidget;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class ULoseMenuWidget* LoseWidget;
};
