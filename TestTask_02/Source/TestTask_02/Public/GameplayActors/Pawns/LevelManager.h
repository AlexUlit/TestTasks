#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "LevelManager.generated.h"

UCLASS()
class TESTTASK_02_API ALevelManager : public APawn
{
	GENERATED_BODY()

public:
	ALevelManager();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Spawn")
	TArray<AActor*> Cameras;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Spawn")
	TArray<AActor*> Nests;

private:
	void ChangeCamera();
	void AllowChangeCamera();
	void FirstNestOpen();
	void SecondNestOpen();
	void ThirdNestOpen();

	const float CameraChangingTime = 2.0f;
	int32 CameraIndex;
	bool bCanChangeCamera = true;
	FTimerHandle SmoothCameraChangeHandle;
};
