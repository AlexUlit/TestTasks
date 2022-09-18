#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "NestInterface.generated.h"


UINTERFACE(MinimalAPI)
class UNestInterface : public UInterface
{
	GENERATED_BODY()
};
class TESTTASK_02_API INestInterface
{
	GENERATED_BODY()

public:
	virtual void SpawnSnail(){};
};
