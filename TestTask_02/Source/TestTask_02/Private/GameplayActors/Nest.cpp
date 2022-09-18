#include "GameplayActors/Nest.h"

ANest::ANest()
{
	PrimaryActorTick.bCanEverTick = false;
	NestMesh = CreateDefaultSubobject<UStaticMeshComponent>("SnailMesh");
}


void ANest::BeginPlay()
{
	Super::BeginPlay();
}

void ANest::SpawnSnail()
{
	if (!GetWorld() || Snail)
	{
		return;
	}
	
	INestInterface::SpawnSnail();
	FTransform SpawnLocAndRotation;
	SpawnLocAndRotation.SetLocation(GetActorLocation());
	SpawnLocAndRotation.SetRotation(GetActorRotation().Quaternion());
	Snail = GetWorld()->SpawnActorDeferred<ASnail_Base>(SnailClass, SpawnLocAndRotation);
	
	if (Snail)
	{
	Snail->GoalLocation_Loc = GoalLocation;
	Snail->FinishSpawning(SpawnLocAndRotation);
	Snail->MovingToGoal();
	}
}


