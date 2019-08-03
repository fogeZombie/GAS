//==============================================================================
// BFShipPart.cpp
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#include "BFShipPart.h"

#pragma optimize("", off)

//==============================================================================
ABFShipPart::ABFShipPart() {
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

    _abilityCmp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Abilities"));
}

//==============================================================================
void ABFShipPart::BeginPlay() {
    Super::BeginPlay();
}

//==============================================================================
void ABFShipPart::Tick(float dt) {
    Super::Tick(dt);
}

#pragma optimize("", on)
