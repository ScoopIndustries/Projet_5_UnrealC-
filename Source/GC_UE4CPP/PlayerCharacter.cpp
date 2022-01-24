// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);	
	CameraBoom->bUsePawnControlRotation = true; // fait pivoter le bras en fonction do character

	CameraFollow = CreateDefaultSubobject<UCameraComponent>(FName("CameraFollow"));
	CameraFollow->SetupAttachment(CameraBoom);
	CameraFollow->bUsePawnControlRotation = false; // camera rotationne independament du character

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate

	// Permet la rotation du character vers la direction actuelle
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward); // appel la fonction "MoveForward"
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight); // appel la fonction "MoveRight"

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Zoom", this, &APlayerCharacter::CameraZoom);

}

// fonction pour avancer / reculer
void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

// fonction pour right / left
void APlayerCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

// Zoom de la camera (zoom / dézoom limité)
void APlayerCharacter::CameraZoom(float Value)
{
	ValueZoom = CameraFollow->FieldOfView;

	if (Value > 0.1f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Zoom In !"));

		if (ValueZoom > 50.f)
		{
			ChangeValueZoom = ValueZoom - ValueProgressZoom;
		}
		
		CameraFollow->SetFieldOfView(ChangeValueZoom);
	}
	else if (Value < -0.1f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Zoom Out !"));

		if (ValueZoom < 130.f)
		{
			ChangeValueZoom = ValueZoom + ValueProgressZoom;
		}

		CameraFollow->SetFieldOfView(ChangeValueZoom);
	}
}