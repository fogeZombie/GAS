// Copyright BroachForge 2019

#include "GAS_ANS_AbilityBranch.h"

#include "GameplayAbility.h"

UGAS_ANS_AbilityBranch::UGAS_ANS_AbilityBranch(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Ability = nullptr;
	FireTime = 0.0f;
	HasFired = false;
}

UGameplayAbility* UGAS_ANS_AbilityBranch::GetBufferedAbility() const
{
	return Ability.GetDefaultObject();
}

void UGAS_ANS_AbilityBranch::NotifyBegin(USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration)
{
	AnimInstance = MeshComp->GetAnimInstance();
	HasFired = false;

	Received_NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UGAS_ANS_AbilityBranch::NotifyTick(USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (AnimInstance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("UGAS_ANS_AbilityBranch::NotifyTick: Cannot find anim instance."));
		return;
	}

	float animationMontage_CurrentTime = AnimInstance->Montage_GetPosition(AnimInstance->GetCurrentActiveMontage());

	if (HasFired == false && animationMontage_CurrentTime >= FireTime)
	{
		Received_Fire(MeshComp);
		HasFired = true;
	}

	Received_NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UGAS_ANS_AbilityBranch::NotifyEnd(USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	Received_NotifyEnd(MeshComp, Animation);
}

EAbilityBranchInputType UGAS_ANS_AbilityBranch::GetInputType() const
{
	return InputType;
}

FString UGAS_ANS_AbilityBranch::GetNotifyName_Implementation() const
{
	FString input_type_string;

	switch (InputType)
	{
	case EAbilityBranchInputType::ABI_None:
		input_type_string = FString(TEXT("None"));
		break;
	case EAbilityBranchInputType::ABI_Face_Up:
		input_type_string = FString(TEXT("ABI_Face_Up"));
		break;
	case EAbilityBranchInputType::ABI_Face_Down:
		input_type_string = FString(TEXT("ABI_Face_Down"));
		break;
	case EAbilityBranchInputType::ABI_Face_Left:
		input_type_string = FString(TEXT("ABI_Face_Left"));
		break;
	case EAbilityBranchInputType::ABI_Face_Right:
		input_type_string = FString(TEXT("ABI_Face_Right"));
		break;
	case EAbilityBranchInputType::ABI_Bumper_Left:
		input_type_string = FString(TEXT("ABI_Bumper_Left"));
		break;
	case EAbilityBranchInputType::ABI_Bumper_Right:
		input_type_string = FString(TEXT("ABI_Bumper_Right"));
		break;
	case EAbilityBranchInputType::ABI_Trigger_Left:
		input_type_string = FString(TEXT("ABI_Trigger_Left"));
		break;
	case EAbilityBranchInputType::ABI_Trigger_Right:
		input_type_string = FString(TEXT("ABI_Trigger_Right"));
		break;
	case EAbilityBranchInputType::ABI_Dpad_Up:
		input_type_string = FString(TEXT("ABI_Dpad_Up"));
		break;
	case EAbilityBranchInputType::ABI_Dpad_Down:
		input_type_string = FString(TEXT("ABI_Dpad_Down"));
		break;
	case EAbilityBranchInputType::ABI_Dpad_Left:
		input_type_string = FString(TEXT("ABI_Dpad_Left"));
		break;
	case EAbilityBranchInputType::ABI_Dpad_Right:
		input_type_string = FString(TEXT("ABI_Dpad_Right"));
		break;
	default:
		input_type_string = FString(TEXT("????"));
		break;
	}

	if (Ability != nullptr)
	{
		return FString::Printf(TEXT("%s: %s @ %.3f"), *input_type_string, *Ability->GetName(), FireTime);
	}

	return FString::Printf(TEXT("%s: Root @ %.3f"), *input_type_string, FireTime);
}

