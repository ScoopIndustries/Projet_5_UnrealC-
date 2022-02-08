// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components\WidgetComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = GetMesh();

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(FName("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);	
	CameraBoom->TargetArmLength = 350.0f; // distance entre la camera et le personnage par default
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

	// Ratio de rotation
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::CallbackComponentBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &APlayerCharacter::CallbackComponentEndOverlap);
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

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput); // tourner la camera
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput); // tourner le character selon la direction de la camera
	PlayerInputComponent->BindAxis("Zoom", this, &APlayerCharacter::CameraZoom); // zommer la camera

	PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &APlayerCharacter::PickUpObject); // prendre l'object
	//PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &APlayerCharacter::DropObject);
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
	ValueZoom = CameraBoom->TargetArmLength; // prend la valeur d'écart entre la camera et le character

	// si zoom in
	if (Value > ConditionForZoom)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Zoom In !"));

		if (ValueZoom > ValueZoomMax)
		{
			CameraBoom->TargetArmLength -= ValueProgressZoom;
		}
	}
	// si zoom out 
	else if (Value < -ConditionForZoom)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Zoom Out !"));

		if (ValueZoom < ValueZoomMin)
		{
			CameraBoom->TargetArmLength += ValueProgressZoom;
		}
	}
}

void APlayerCharacter::CallbackComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Food == nullptr)
	{
		Food = Cast<AFood>(OtherActor);
	}
}

void APlayerCharacter::CallbackComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("End Overlap !"));

	if (Food == OtherActor && !IsCarrying)
	{
		Food = nullptr;
	}
}

FVector APlayerCharacter::RecupPlayerVelocity()
{
	PlayerVelocity = GetVelocity();

	return PlayerVelocity;
}

void APlayerCharacter::PickUpObject()
{
	if (!IsCarrying)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("PickUp"));

		//PlayerGameState = Cast<APlayerGameState>(GetWorld()->GetGameState()); // A enlever pour le bien du projet !!!
		//PlayerGameState->FoodCollected += 1; // A enlever pour le bien du projet !!!

		if (Food != nullptr) {
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Press E for take food"));

			FAttachmentTransformRules Rules(EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, false);
			Food->AttachToComponent(SkeletalMesh, Rules, TEXT("Fist_R_endSocket"));

			IsCarrying = true;
		}
	}
	else if (IsCarrying)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Drop")); 

		FDetachmentTransformRules rules(EDetachmentRule::KeepWorld, EDetachmentRule::KeepRelative, EDetachmentRule::KeepWorld, false);
		Food->DetachFromActor(rules);
		//Food = nullptr;

		IsCarrying = false;
	}
}

void APlayerCharacter::DropObject()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Drop"));
}