//==============================================================================
// ABFShip.h
// 
// Jordan Massey
// 03.08.2019
//==============================================================================

#include "Goods.generated.h"

USTRUCT(BlueprintType)
struct FMarketGood {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Goods")
    FName name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Goods")
    float price;
};
