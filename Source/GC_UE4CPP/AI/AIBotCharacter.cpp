// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBotCharacter.h"
#include "Food.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AAIBotCharacter::AAIBotCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SKmesh = GetMesh();
	socket = TEXT("Fist_R_endSocket");
}

// Called when the game starts or when spawned
void AAIBotCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Spawn Actor on the socket
	Food = GetWorld()->SpawnActor<AFood>(FoodClass, SocketR, CharRotation, SpawnInfo);
	FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	Food->AttachToComponent(SKmesh, Rules, socket);
}

// Called every frame
void AAIBotCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Food != nullptr)
	{
		isCarrying = true;
	}
	else
	{
		isCarrying = false;
	}

}

// Called to bind functionality to input
void AAIBotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


