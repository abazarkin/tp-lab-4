#include "gtest/gtest.h"
#include "VendingMachineDrink.h"

TEST(VendingMachineDrink, ConstructorAndAccessors_Test1)
{
    VendingMachineDrink drink(17, 35, "Drink Name");

    ASSERT_EQ(17, drink.GetId());
    ASSERT_EQ(35, drink.GetPrice());
    ASSERT_EQ("Drink Name", drink.GetName());
}
TEST(VendingMachineDrink, ConstructorAndAccessors_Test2)
{
    VendingMachineDrink drink(13, 48, "Another Drink Name");

    ASSERT_EQ(13, drink.GetId());
    ASSERT_EQ(48, drink.GetPrice());
    ASSERT_EQ("Another Drink Name", drink.GetName());
}
