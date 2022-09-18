#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/NestInterface.h"
#include "Pawns/Snail_Base.h"
#include "Nest.generated.h"

UCLASS()
class TESTTASK_02_API ANest : public AActor, public INestInterface
{
	GENERATED_BODY()
	
public:	
	ANest();
	virtual void SpawnSnail() override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ASnail_Base> SnailClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (MakeEditWidget = true), Category = "Target")
	FVector GoalLocation{200.0f, 0.0f, 100.0f};
	
	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* NestMesh;
	
private:
	ASnail_Base* Snail;
};
