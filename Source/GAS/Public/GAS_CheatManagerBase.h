// Copyright BroachForge 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "GAS_CheatManagerBase.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UGAS_CheatManagerBase : public UCheatManager
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Exec)
	void FogeTestFunction();
};
