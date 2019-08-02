// Copyright BroachForge 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GAS_DebugMenu_ItemWidget.generated.h"

class UGAS_DebugMenu_MenuContents;

UENUM(BlueprintType)
enum class EDebugMenuItemCommandType : uint8
{
	DMIC_Exec	UMETA(DisplayName = "Exec"),
	DMIC_Bool 	UMETA(DisplayName = "Bool"),
	DMIC_Int 	UMETA(DisplayName = "Int"),
	DMIC_Float 	UMETA(DisplayName = "Float"),
	DMIC_Menu	UMETA(DisplayName = "Menu"),
};

USTRUCT(BlueprintType)
struct FDebugMenu_ItemWidgetData
{
	GENERATED_BODY()

	// Indicate if the item is a command or a menu
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDebugMenuItemCommandType CommandType;

	// The name of the item, also used for menu item's breadcrumb trail
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName DisplayName;

	// Tooltip for the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Tooltip;

	// If it's a command, the literal command string
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommandString;

	// If it's a menu, where to look for its contents
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGAS_DebugMenu_MenuContents* MenuContents;
};

/**
 * 
 */
UCLASS()
class GAS_API UGAS_DebugMenu_ItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	FDebugMenu_ItemWidgetData DMIW_Data;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "DebugMenu")
	int GetDebugMenuVariableValue_Bool();

	UFUNCTION(BlueprintCallable, Category = "DebugMenu")
	void ExecuteDebugMenuCommand();
};
