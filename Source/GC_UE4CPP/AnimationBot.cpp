// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimationBot.h"

UAnimationBot::UAnimationBot()
{
	Speed = 0.0f;
}

void UAnimationBot::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AActor* OwningActor = GetOwningActor();
	AAIBotCharacter* character = Cast<AAIBotCharacter>(OwningActor);

	if (OwningActor != nullptr)
	{
		Speed = OwningActor->GetVelocity().Size();
		if (character != nullptr)
		{
			isCarry = character->isCarrying;
		}
	}

}

