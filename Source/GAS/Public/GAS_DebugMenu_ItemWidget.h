// Copyright BroachForge 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GAS_DebugMenu_ItemWidget.generated.h"

class UGAS_DebugMenu_MenuContents;

UENUM(BlueprintType)
enum class EDebugMenuItemWidgetType : uint8
{
	DMIW_Command 	UMETA(DisplayName = "Command"),
	DMIW_Menu 		UMETA(DisplayName = "Menu"),
};

USTRUCT(BlueprintType)
struct FDebugMenu_ItemWidgetData
{
	GENERATED_BODY()

	// Indicate if the item is a command or a menu
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDebugMenuItemWidgetType EntryType;

	// The name of the item, also used for menu item's breadcrumb trail
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName DisplayName;

	// Tooltip for the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Tooltip;

	// If it's a menu, where to look for its contents
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGAS_DebugMenu_MenuContents* MenuContents;

	// If it's a command, the literal command string
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CommandString;

	// Whether or not the UI should display if the command is on or off
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bToggleCommand;

	// Whether or not the UI should pass additional input, may subclass this.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUsesInput;
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
};
