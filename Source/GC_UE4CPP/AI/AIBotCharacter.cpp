// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBotCharacter.h"
#include "Food.h"
#include "Components/SceneComponent.h"
#include "Waypoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "../PlayerGameMode.h"
#include "GameFramework/CharacterMovementComponent.h"
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
	auto GameMode = GetWorld()->GetAuthGameMode();
	auto CastGM = Cast<APlayerGameMode>(GameMode);

	auto CharaMove = this->GetCharacterMovement();
	CharaMove->MaxWalkSpeed = 450.0f;


	//Spawn Actor (Food) on the socket
	FActorSpawnParameters SpawnInfo;
	FRotator CharRotation = GetControlRotation();
	FVector SocketR;
	FoodActor = GetWorld()->SpawnActor<AFood>(FoodClass, SocketR, CharRotation, SpawnInfo);
	FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	FoodActor->AttachToComponent(SKmesh, Rules, socket);
}


// Called every frame
void AAIBotCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FoodActor != nullptr)
	{
		isCarrying = true;
		auto CharaMove = this->GetCharacterMovement();
		CharaMove->MaxWalkSpeed = CarrySpeed;
		
	}
	else
	{
		isCarrying = false;
		auto CharaMove = this->GetCharacterMovement();
		CharaMove->MaxWalkSpeed = WalkSpeed;
	}
}

// Called to bind functionality to input
void AAIBotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


