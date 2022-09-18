// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayActors/Pawns/Snail_Base.h"

#include "Controllers/SnailAIController.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASnail_Base::ASnail_Base()
{
	PrimaryActorTick.bCanEverTick = false;
	SnailMesh = CreateDefaultSubobject<USkeletalMeshComponent>("PawnMesh");
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
}

void ASnail_Base::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	GoalLocation_W = GetActorTransform().TransformPosition(GoalLocation_Loc);
}

void ASnail_Base::MovingToGoal_Implementation()
{
}

void ASnail_Base::WhenFinish_Implementation()
{
}
