//==============================================================================
// ABFShip.h
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#pragma once

#include "GameFramework/Actor.h"
#include "AttributeSet.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFShipPart.h"
#include "BFShip.generated.h"

class UDataTable;
class UShipPartDef;

/** Defines attributes for the player's ship */
UCLASS(BlueprintType)
class UBFShipAttributes : public UAttributeSet {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData HP;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData Armor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData AttackPower;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData Evasion;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData CargoSpace;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData PersonnelSpace;
};

/** Class for the player's ship */
UCLASS(Blueprintable)
class ABFShip : public AActor, public IAbilitySystemInterface {
    GENERATED_BODY()

public:
    ABFShip();

    virtual void OnConstruction(const FTransform& transform);
    virtual void BeginPlay() override;
    virtual void Tick(float dt) override;

    UAbilitySystemComponent* GetAbilitySystemComponent() const override { return _abilityCmp; }

    UFUNCTION(BlueprintCallable, Category = "Ship")
    void SetBaseAttribute(FGameplayAttribute attr, float value);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
    UAbilitySystemComponent * _abilityCmp = nullptr;
};

UCLASS(BlueprintType)
class UBFShipLib : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Ship")
    static bool PartFitsSlot(UShipPartDef* partDef, EBFShipSlotType slot);
};
