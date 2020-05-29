#include "gtest/gtest.h"
#include "TestCommons.h"
#include "VendingMachine.h"

TEST(VendingMachine, TurnOn)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n", streamWriter.str());
}
TEST(VendingMachine, TurnOn_TwoSequentialCalls)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.TurnOn();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "The machine is in an invalid state for this action." + "\n", streamWriter.str());
}

TEST(VendingMachine, TurnOff)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.TurnOff();

    ASSERT_EQ(VENDINGMACHINESTATE_TURNEDOFF, vendingMachine.GetState());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "The machine has been turned off." + "\n", streamWriter.str());
}
TEST(VendingMachine, TurnOff_TwoSequentialCalls)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.TurnOff();
    vendingMachine.TurnOff();

    ASSERT_EQ(VENDINGMACHINESTATE_TURNEDOFF, vendingMachine.GetState());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "The machine has been turned off." + "\n"
        + "The machine is in an invalid state for this action." + "\n", streamWriter.str());
}

TEST(VendingMachine, ShowMenu)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.ShowMenu();

    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "Menu:" + "\n"
        + " Id   " + "|" + " Name             " + "|" + " Price " + "|" + "\n"
        + " 0    " + "|" + " Water            " + "|" + " $1    " + "|" + "\n"
        + " 1    " + "|" + " Tea              " + "|" + " $2    " + "|" + "\n"
        + " 2    " + "|" + " Coffee           " + "|" + " $5    " + "|" + "\n", streamWriter.str());
}

TEST(VendingMachine, AddMoney)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(5, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n", streamWriter.str());
}
TEST(VendingMachine, AddMoney_TwoSequentialCalls)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.AddMoney(10);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(15, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "$10 accepted." + "\n", streamWriter.str());
}

TEST(VendingMachine, SelectDrink)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);

    ASSERT_EQ(VENDINGMACHINESTATE_VALIDATINGORDER, vendingMachine.GetState());
    ASSERT_EQ(5, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "The drink you ordered has been found." + "\n", streamWriter.str());
}
TEST(VendingMachine, SelectDrink_TwoSequentialCalls)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.SelectDrink(0);

    ASSERT_EQ(VENDINGMACHINESTATE_VALIDATINGORDER, vendingMachine.GetState());
    ASSERT_EQ(5, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "The drink you ordered has been found." + "\n"
        + "The machine is in an invalid state for this action." + "\n", streamWriter.str());
}
TEST(VendingMachine, SelectDrink_NotEnoughMoney)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(1);
    vendingMachine.SelectDrink(2);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(1, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$1 accepted." + "\n"
        + "The drink you ordered has been found." + "\n"
        + "You do not have enough money to purchase this drink. Add money or try selecting another one." + "\n", streamWriter.str());
}
TEST(VendingMachine, SelectDrink_NoDrinkFound)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(1);
    vendingMachine.SelectDrink(3);

    ASSERT_EQ(VENDINGMACHINESTATE_ACCEPTINGPAYMENT, vendingMachine.GetState());
    ASSERT_EQ(1, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$1 accepted." + "\n"
        + "The drink you ordered has not been found. Try another one." + "\n", streamWriter.str());
}

TEST(VendingMachine, Confirm)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.Confirm();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "The drink you ordered has been found." + "\n"
        + "The drink is now being cooked." + "\n"
        + "The drink is ready now." + "\n"
        + "$4 is your money change." + "\n", streamWriter.str());
}
TEST(VendingMachine, Confirm_TwoSequentialCalls)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.Confirm();
    vendingMachine.Confirm();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ(std::string( "The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "The drink you ordered has been found." + "\n"
        + "The drink is now being cooked." + "\n"
        + "The drink is ready now." + "\n"
        + "$4 is your money change." + "\n"
        + "The machine is in an invalid state for this action." + "\n", streamWriter.str());
}

TEST(VendingMachine, Abort_AcceptingPayment)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.Abort();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "$5 is your money change." + "\n", streamWriter.str());
}
TEST(VendingMachine, Abort_ValidatingOrder)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);
    VendingMachine vendingMachine(drinks, &logger);

    vendingMachine.TurnOn();
    vendingMachine.AddMoney(5);
    vendingMachine.SelectDrink(0);
    vendingMachine.Abort();

    ASSERT_EQ(VENDINGMACHINESTATE_WAITING, vendingMachine.GetState());
    ASSERT_EQ(0, vendingMachine.GetMoney());
    ASSERT_EQ(std::string("The machine has been turned on.") + "\n"
        + "$5 accepted." + "\n"
        + "The drink you ordered has been found." + "\n"
        + "$5 is your money change." + "\n", streamWriter.str());
}