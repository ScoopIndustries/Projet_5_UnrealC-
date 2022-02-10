// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PlayerGameState.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API APlayerGameState : public AGameStateBase
{
	GENERATED_BODY()

public :

	UPROPERTY(VisibleAnywhere)
		float FoodCollected = 0.f;
	UPROPERTY(VisibleAnywhere)
		int8 Cycle = 0;
	
	UFUNCTION()
		void UpdateCycle();
};
