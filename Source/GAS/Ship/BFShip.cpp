//==============================================================================
// ABFShip.cpp
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#include "BFShip.h"

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
