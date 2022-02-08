// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Runtime/UMG/Public/Components/TextBlock.h>
#include <Runtime/UMG/Public/Components/Button.h>
#include "WinMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GC_UE4CPP_API UWinMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	void NativeConstruct() override;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameMode* PlayerGameMode;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class APlayerGameState* PlayerGameState;

	UPROPERTY(meta = (BindWidget))
		UTextBlock* WinLabel;

	UPROPERTY(meta = (BindWidget))
		class UButton* RestartButton;

	UFUNCTION()
		void RestartGame();
};
