// Fill out your copyright notice in the Description page of Project Settings.


#include "Waypoint.h"
#include "AIBotCharacter.h"

// Sets default values
AWaypoint::AWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root Component"));
	StaticMesh->SetupAttachment(RootComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxComponent->SetupAttachment(StaticMesh);
	//BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&AWaypoint::OnEnterTrigger);
}

// Called when the game starts or when spawned
void AWaypoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AWaypoint::GetPlateLocation()
{
	FVector location = GetActorLocation();

		return location;
}

void AWaypoint::OnEnterTrigger(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

