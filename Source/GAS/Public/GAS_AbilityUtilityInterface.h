// Copyright BroachForge 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GAS_AbilityUtilityInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGAS_AbilityUtilityInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GAS_API IGAS_AbilityUtilityInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Abilities that allow for input buffer management.
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "I_AbilityUtilityInterface")
	void I_BufferAbilityAdd();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "I_AbilityUtilityInterface")
	void I_BufferAbilityRemove();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "I_AbilityUtilityInterface")
	void I_BufferAbilitySetFireState();

};
