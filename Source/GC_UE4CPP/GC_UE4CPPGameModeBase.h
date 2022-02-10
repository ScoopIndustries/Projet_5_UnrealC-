// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GC_UE4CPPGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API AGC_UE4CPPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	float GetFoodCollected() const { return FoodCollected; }
	float GetMaxFoodConditionWin() const { return MaxFoodConditionWin; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		float FoodCollected;

	UPROPERTY(EditAnywhere)
		float MaxFoodConditionWin;

	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UScoreWidget* ScoreWidget;


	
};
