// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"

UPlayerAnim::UPlayerAnim()
{

}

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AActor* OwningActor = GetOwningActor();
	APlayerCharacter* character = Cast<APlayerCharacter>(OwningActor);

	if (OwningActor != nullptr)
	{
		Speed = OwningActor->GetVelocity().Size();
		if (character != nullptr)
		{
			isCarry = character->IsCarrying;
		}
	}

}