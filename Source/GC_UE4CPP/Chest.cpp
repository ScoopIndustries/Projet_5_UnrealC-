// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include <GC_UE4CPP/PlayerCharacter.h>

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	RootComponent = StaticMesh;

	StaticMeshChestBaseTop = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshChestBaseTop"));
	StaticMeshChestBaseTop->SetupAttachment(RootComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	BoxCollision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AChest::CallbackComponentBeginOverlap);

	PlayerGameState = Cast<APlayerGameState>(GetWorld()->GetGameState());
	
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChest::CallbackComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Joueur detecte !!!"));

		PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

		if (PlayerCharacter->IsCarrying)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Le joueur porte un Objet"));

			PlayerCharacter->Food->Destroy();
			PlayerCharacter->Food = nullptr;
			PlayerCharacter->IsCarrying = false;
			PlayerGameState->FoodCollected++;
		}
	}
}
