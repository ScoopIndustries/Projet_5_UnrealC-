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

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		float MaxFoodConditionWin = 10.f;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UScoreWidget* ScoreWidget;
};
