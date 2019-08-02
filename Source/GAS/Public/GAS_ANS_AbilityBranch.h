// Copyright BroachForge 2019

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GAS_ANS_AbilityBranch.generated.h"

// enum for input buffer
UENUM(BlueprintType)
enum class EAbilityBranchInputType : uint8
{
	ABI_None			UMETA(DisplayName = "None"),
	ABI_Face_Up			UMETA(DisplayName = "None"),
	ABI_Face_Down		UMETA(DisplayName = "None"),
	ABI_Face_Left		UMETA(DisplayName = "None"),
	ABI_Face_Right		UMETA(DisplayName = "None"),
	ABI_Bumper_Left		UMETA(DisplayName = "None"),
	ABI_Bumper_Right	UMETA(DisplayName = "None"),
	ABI_Trigger_Left	UMETA(DisplayName = "None"),
	ABI_Trigger_Right	UMETA(DisplayName = "None"),
	ABI_Dpad_Up			UMETA(DisplayName = "None"),
	ABI_Dpad_Down		UMETA(DisplayName = "None"),
	ABI_Dpad_Left		UMETA(DisplayName = "None"),
	ABI_Dpad_Right		UMETA(DisplayName = "None"),
};

class UGameplayAbility;

/**
 * 
 */
UCLASS(Blueprintable, meta = (DisplayName = "Ability Branch"))
class GAS_API UGAS_ANS_AbilityBranch : public UAnimNotifyState
{
	GENERATED_BODY()
	
	UGAS_ANS_AbilityBranch(const FObjectInitializer& ObjectInitializer);

	UAnimInstance* AnimInstance = nullptr;
	bool HasFired;

	// Properties to edit in the AnimNotifyState
	UPROPERTY(EditAnywhere, Category = "AbilityBranch", meta = (ToolTip = "The input type associated with this branch."))
	EAbilityBranchInputType InputType;

	UPROPERTY(EditAnywhere, Category = "AbilityBranch", meta = (ToolTip = "The ability to branch to when activating the input type."))
	TSubclassOf<UGameplayAbility> Ability;

	UPROPERTY(EditAnywhere, Category = "AbilityBranch", meta = (ToolTip = "After the time indicated by FireTime (as a percentage of the total animation montage), the move branches with either buffered or fresh input."))
	float FireTime;

	UFUNCTION(BlueprintCallable, Category = "AbilityBranch")
	UGameplayAbility* GetBufferedAbility() const;

	// Overrides
	virtual void NotifyBegin(class USkeletalMeshComponent * MeshComp, class UAnimSequenceBase * Animation, float TotalDuration) override;
	virtual void NotifyTick(class USkeletalMeshComponent * MeshComp, class UAnimSequenceBase * Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(class USkeletalMeshComponent * MeshComp, class UAnimSequenceBase * Animation) override;

	UFUNCTION(BlueprintCallable, Category = "CombatCollision")
	EAbilityBranchInputType GetInputType() const;

	// Overridden from UAnimNotifyState to provide custom notify name.
	FString GetNotifyName_Implementation() const override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool Received_Fire(USkeletalMeshComponent* MeshComp) const;
};
