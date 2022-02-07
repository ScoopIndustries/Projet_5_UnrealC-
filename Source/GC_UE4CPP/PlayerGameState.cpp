// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameState.h"

void APlayerGameState::UpdateCycle()
{
	Cycle++;
	if (Cycle > 4)
	{
		Cycle = 0;
	}
}
