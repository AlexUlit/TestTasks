#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Snail_Base.generated.h"

class UFloatingPawnMovement;
class UProjectileMovementComponent;

UCLASS()
class TESTTASK_02_API ASnail_Base : public APawn
{
	GENERATED_BODY()

public:

	ASnail_Base();
	FVector GoalLocation_Loc;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Logic")
	void MovingToGoal();
	

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Logic")
	void WhenFinish();

	UPROPERTY(BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* SnailMesh;
	
	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* MovementComponent;

	UPROPERTY(BlueprintReadOnly)
	FVector GoalLocation_W;

	UPROPERTY(BlueprintReadOnly)
	FVector StartLocation;
};
