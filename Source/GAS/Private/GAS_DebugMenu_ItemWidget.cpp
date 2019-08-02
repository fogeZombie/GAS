// Copyright BroachForge 2019

#include "GAS_DebugMenu_ItemWidget.h"

#include "Engine/Console.h"

int UGAS_DebugMenu_ItemWidget::GetDebugMenuVariableValue_Bool()
{
	IConsoleVariable* Variable = IConsoleManager::Get().FindConsoleVariable(*DMIW_Data.CommandString);
	if (Variable && !Variable->TestFlags(ECVF_Unregistered))
	{
		return Variable->GetInt();
	}

	UE_LOG(LogTemp, Error, TEXT("UGAS_DebugMenu_ItemWidget::GetDebugMenuVariableValue_Bool failed to find the specified variable: %s"), *DMIW_Data.CommandString);
	return -1;
}

void UGAS_DebugMenu_ItemWidget::ExecuteDebugMenuCommand()
{
	if (DMIW_Data.CommandType == EDebugMenuItemCommandType::DMIC_Exec)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Exec type: %s"), *DMIW_Data.CommandString);
		GetOwningPlayer()->ConsoleCommand(*DMIW_Data.CommandString);
	}
	else if (DMIW_Data.CommandType == EDebugMenuItemCommandType::DMIC_Bool)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Bool type."));
		IConsoleVariable* Variable = IConsoleManager::Get().FindConsoleVariable(*DMIW_Data.CommandString);
		if (Variable && !Variable->TestFlags(ECVF_Unregistered))
		{
			int32 value = Variable->GetInt();

			switch (value)
			{
				case 0:  value = 1; break;
				case 1:  value = 0; break;
				default: value = 0; break; // handles case of flag values leaving the 'unassigned' state
			}

			Variable->Set(value, ECVF_SetByConsole);
		}
	}
	else if (DMIW_Data.CommandType == EDebugMenuItemCommandType::DMIC_Int)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Int type."));
		IConsoleVariable* Variable = IConsoleManager::Get().FindConsoleVariable(*DMIW_Data.CommandString);
		if (Variable && !Variable->TestFlags(ECVF_Unregistered))
		{
			int32 value = Variable->GetInt();

			// pull new value from DMIW_Data

			// Need a setup for defining min/max
// 			value = FMath::Clamp(value, Binding.Int.Min, Binding.Int.Max);

			UE_LOG(LogTemp, Warning, TEXT("%s = %d"), *DMIW_Data.CommandString, value);
			Variable->Set(value, ECVF_SetByConsole);
		}
	}
	else if (DMIW_Data.CommandType == EDebugMenuItemCommandType::DMIC_Float)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Float type."));
		IConsoleVariable* Variable = IConsoleManager::Get().FindConsoleVariable(*DMIW_Data.CommandString);
		if (Variable && !Variable->TestFlags(ECVF_Unregistered))
		{
			float value = Variable->GetFloat();

			// pull new value from DMIW_Data
// 			value = FMath::Clamp(value, Binding.Float.Min, Binding.Float.Max);

			UE_LOG(LogTemp, Warning, TEXT("%s = %f"), *DMIW_Data.CommandString, value);
			Variable->Set(value, ECVF_SetByConsole);
		}
	}
}

