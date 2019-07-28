// Copyright BroachForge 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "GAS_DebugMenu_ItemWidget.h"

#include "GAS_DebugMenu_MenuContents.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GAS_API UGAS_DebugMenu_MenuContents : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DebugMenu", meta = (ToolTip = "Array of menu contents."))
	TArray<FDebugMenu_ItemWidgetData> MenuContents;
};
