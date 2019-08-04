//==============================================================================
// BFShipPart.h
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#pragma once

#include "GameFramework/Actor.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "BFShipPart.generated.h"

class UDataTable;
class UShipWeaponDef;

UENUM(BlueprintType)
enum class EBFShipSlotType : uint8 {
    Simple,
    Weapon,
    Engine
};

/** Base data asset for a ship part */
UCLASS(BlueprintType)
class UShipPartDef : public UDataAsset {
    GENERATED_BODY()

public:
    /** Effects to apply to the ship when placed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
    TArray<UGameplayEffect *> shipEffects;
    /** Array of compatible slot types. All parts will fit a Simple slot implicitly */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
    TArray<EBFShipSlotType> compatibleSlots;
};

/** Defines attributes for a ship part. */
UCLASS(BlueprintType)
class UBFShipPartAttributes : public UAttributeSet {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData WeaponAttack;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData WeaponDamage;
};

/** Base class for a ship part */
UCLASS(Blueprintable)
class ABFShipPart : public AActor {
    GENERATED_BODY()

public:
    ABFShipPart();

    virtual void BeginPlay() override;
    virtual void Tick(float dt) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
    UAbilitySystemComponent * _abilityCmp = nullptr;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship", meta=(ExposeOnSpawn=true))
    UShipPartDef * _partDef = nullptr;
};
