#include "GameplayActors/Pawns/LevelManager.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/NestInterface.h"


ALevelManager::ALevelManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetViewTargetWithBlend(Cameras[0], 2);
}

void ALevelManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("ABChangeCamera", IE_Pressed, this, &ALevelManager::ChangeCamera);
	PlayerInputComponent->BindAction("ABSnail_01", IE_Pressed, this, &ALevelManager::FirstNestOpen);
	PlayerInputComponent->BindAction("ABSnail_02", IE_Pressed, this, &ALevelManager::SecondNestOpen);
	PlayerInputComponent->BindAction("ABSnail_03", IE_Pressed, this, &ALevelManager::ThirdNestOpen);
}

void ALevelManager::ChangeCamera()
{
	
	if (!GetWorld() || !bCanChangeCamera)
	{ 
		return;
	}
	bCanChangeCamera = false;
	CameraIndex = (++CameraIndex % Cameras.Num());
	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetViewTargetWithBlend(Cameras[CameraIndex], CameraChangingTime);
	
	GetWorld()->GetTimerManager().SetTimer(SmoothCameraChangeHandle, this,  &ALevelManager::AllowChangeCamera, CameraChangingTime);
}

void ALevelManager::AllowChangeCamera()
{
	bCanChangeCamera = true;
}

static void SendMessage(AActor* CurrentNest)
{
	
	if (INestInterface* MyInterface = Cast<INestInterface>(CurrentNest))
	{
		MyInterface->SpawnSnail();
	}
}

void ALevelManager::FirstNestOpen()
{
	SendMessage(Nests[0]);
}

void ALevelManager::SecondNestOpen()
{
	SendMessage(Nests[1]);
}

void ALevelManager::ThirdNestOpen()
{
	SendMessage(Nests[2]);
}