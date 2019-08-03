//==============================================================================
// BFShipPart.h
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#include "GameFramework/Actor.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "BFShipPart.generated.h"

class UDataTable;
class UShipWeaponDef;

/** Base data asset for a ship part */
UCLASS(BlueprintType)
class UShipPartDef : public UDataAsset {
    GENERATED_BODY()

public:
    /** Effects to apply to the ship when placed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
    TArray<UGameplayEffect *> shipEffects;

    /** Optional weapon data if this part is a weapon */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
    UShipWeaponDef * weapon = nullptr;
};

/** Defines attributes for the player's ship */
UCLASS(BlueprintType)
class UBFWeaponAttributes : public UAttributeSet {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData Attack;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData Damage;
};


/** Data asset for weapon parts */
UCLASS(BlueprintType)
class UShipWeaponDef : public UDataAsset {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    TSubclassOf<UBFWeaponAttributes> attributeClass = UBFWeaponAttributes::StaticClass();
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


/** Base class for a ship weapon actor */
UCLASS(Blueprintable)
class ABFShipWeapon : public ABFShipPart {
    GENERATED_BODY()

public:
    ABFShipWeapon();

    virtual void BeginPlay() override;
    virtual void Tick(float dt) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
    UShipWeaponDef * _weaponDef = nullptr;
};
