#include "gtest/gtest.h"
#include "TestCommons.h"
#include "VendingMachine.h"

using namespace std::string_literals;

TEST(VendingMachine, TurnOn)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ("The machine has been turned on."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, TurnOn_TwoSequentialCalls)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.TurnOn();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "The machine is in an invalid state for this action."s + "\n"s, streamWriter.str());
}

TEST(VendingMachine, TurnOff)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.TurnOff();

    ASSERT_EQ(VENDINGMACHINESTATE_TURNEDOFF, vendingMachine.GetState());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "The machine has been turned off."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, TurnOff_TwoSequentialCalls)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.TurnOff();
    vendingMachine.TurnOff();

    ASSERT_EQ(VENDINGMACHINESTATE_TURNEDOFF, vendingMachine.GetState());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "The machine has been turned off."s + "\n"s
        + "The machine is in an invalid state for this action."s + "\n"s, streamWriter.str());
}

TEST(VendingMachine, ShowMenu)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.ShowMenu();

    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "Menu:"s + "\n"s
        + " Id   "s + "|"s + " Name             "s + "|"s + " Price "s + "|"s + "\n"s
        + " 0    "s + "|"s + " Water            "s + "|"s + " $1    "s + "|"s + "\n"s
        + " 1    "s + "|"s + " Tea              "s + "|"s + " $2    "s + "|"s + "\n"s
        + " 2    "s + "|"s + " Coffee           "s + "|"s + " $5    "s + "|"s + "\n"s, streamWriter.str());
}

TEST(VendingMachine, AddMoney)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(5, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, AddMoney_TwoSequentialCalls)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.AddMoney(10);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(15, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "$10 accepted."s + "\n"s, streamWriter.str());
}

TEST(VendingMachine, SelectDrink)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);

    ASSERT_EQ(VENDINGMACHINESTATE_VALIDATINGORDER, vendingMachine.GetState());
    ASSERT_EQ(5, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "The drink you ordered has been found."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, SelectDrink_TwoSequentialCalls)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.SelectDrink(0);

    ASSERT_EQ(VENDINGMACHINESTATE_VALIDATINGORDER, vendingMachine.GetState());
    ASSERT_EQ(5, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "The drink you ordered has been found."s + "\n"s
        + "The machine is in an invalid state for this action."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, SelectDrink_NotEnoughMoney)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(1);
    vendingMachine.SelectDrink(2);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(1, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$1 accepted."s + "\n"s
        + "The drink you ordered has been found."s + "\n"s
        + "You do not have enough money to purchase this drink. Add money or try selecting another one."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, SelectDrink_NoDrinkFound)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(1);
    vendingMachine.SelectDrink(3);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(1, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$1 accepted."s + "\n"s
        + "The drink you ordered has not been found. Try another one."s + "\n"s, streamWriter.str());
}

TEST(VendingMachine, Confirm)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.Confirm();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "The drink you ordered has been found."s + "\n"s
        + "The drink is now being cooked."s + "\n"s
        + "The drink is ready now."s + "\n"s
        + "$4 is your money change."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, Confirm_TwoSequentialCalls)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.Confirm();
    vendingMachine.Confirm();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "The drink you ordered has been found."s + "\n"s
        + "The drink is now being cooked."s + "\n"s
        + "The drink is ready now."s + "\n"s
        + "$4 is your money change."s + "\n"s
        + "The machine is in an invalid state for this action."s + "\n"s, streamWriter.str());
}

TEST(VendingMachine, Abort_AcceptingPayment)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.Abort();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "$5 is your money change."s + "\n"s, streamWriter.str());
}
TEST(VendingMachine, Abort_ValidatingOrder)
{
    std::ostringstream streamWriter = std::ostringstream();
    TestVendingMachineLogger logger = TestVendingMachineLogger(&streamWriter);
    VendingMachine vendingMachine = VendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.Abort();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ("The machine has been turned on."s + "\n"s
        + "$5 accepted."s + "\n"s
        + "The drink you ordered has been found."s + "\n"s
        + "$5 is your money change."s + "\n"s, streamWriter.str());
}