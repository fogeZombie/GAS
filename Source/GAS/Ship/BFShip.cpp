//==============================================================================
// ABFShip.cpp
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#include "BFShip.h"
#include "BFShipPart.h"

//==============================================================================
ABFShip::ABFShip() {
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    _abilityCmp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Abilities"));
}

//==============================================================================
void ABFShip::OnConstruction(const FTransform& transform) {
    Super::OnConstruction(transform);
}

//==============================================================================
void ABFShip::BeginPlay() {
    Super::BeginPlay();
}

//==============================================================================
void ABFShip::Tick(float dt) {
    Super::Tick(dt);
}

//==============================================================================
bool UBFShipLib::PartIsEngine(UShipPartDef* partDef) {
    return partDef->engineThrust > 0;
}

//==============================================================================
bool UBFShipLib::PartIsWeapon(UShipPartDef* partDef) {
    return partDef->weaponAttack > 0;
}

//==============================================================================
bool UBFShipLib::PartFitsSlot(UShipPartDef* partDef, EBFShipSlotType slot) {
    switch (slot) {
        case EBFShipSlotType::Engine: return PartIsEngine(partDef);
        case EBFShipSlotType::Weapon: return PartIsWeapon(partDef);

        default:
        case EBFShipSlotType::Simple: return true;
    }
}
