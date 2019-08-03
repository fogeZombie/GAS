//==============================================================================
// ABFShip.h
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#include "GameFramework/Actor.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BFShip.generated.h"

class UDataTable;

UENUM(BlueprintType)
enum class EBFShipSlotType : uint8 {
    Simple,
    Weapon,
    Engine
};

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
    FGameplayAttributeData Evasion;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData CargoSpace;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship")
    FGameplayAttributeData PersonnelSpace;
};

/** Class for the player's ship */
UCLASS(Blueprintable)
class ABFShip : public AActor {
    GENERATED_BODY()

public:
    ABFShip();

    virtual void OnConstruction(const FTransform& transform);
    virtual void BeginPlay() override;
    virtual void Tick(float dt) override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
    UAbilitySystemComponent * _abilityCmp = nullptr;
};
