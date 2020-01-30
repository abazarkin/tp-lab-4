#include <cstdint>
#include <vector>
#include <sstream>
#include "VendingMachine.h"
#include "VendingMachineDrink.h"
#include "VendingMachineLogger.h"
#include "VendingMachineState.h"

VendingMachine::VendingMachine(std::vector<VendingMachineDrink> drinks, VendingMachineLogger *logger)
{
    m_drinks = drinks;
    m_logger = logger;
    m_state = VENDINGMACHINESTATE_TURNEDOFF;
    m_selectedDrink = VendingMachineDrink(0, 0, "");
    m_money = 0;
}

bool VendingMachine::ValidatePayment() { return m_money >= m_selectedDrink.GetPrice(); }
void VendingMachine::Cook()
{
    m_logger->LogInformation(std::string("The drink is now being cooked.") + "\n");
    m_logger->LogInformation(std::string("The drink is ready now.") + "\n");
}

VendingMachineState VendingMachine::GetState() { return m_state; }
VendingMachineDrink VendingMachine::GetSelectedDrink() { return m_selectedDrink; }
int32_t VendingMachine::GetMoney() { return m_money; }

void VendingMachine::TurnOn()
{
    if (m_state == VENDINGMACHINESTATE_TURNEDOFF)
    {
        m_state = VENDINGMACHINESTATE_WAITING;
        m_logger->LogInformation(std::string("The machine has been turned on.") + "\n");
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}
void VendingMachine::TurnOff()
{
    if (m_state == VENDINGMACHINESTATE_WAITING)
    {
        m_state = VENDINGMACHINESTATE_TURNEDOFF;
        m_logger->LogInformation(std::string("The machine has been turned off.") + "\n");
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}

void VendingMachine::ShowMenu()
{
    if (m_state != VENDINGMACHINESTATE_TURNEDOFF)
    {
        std::string text;
        text += std::string("Menu:") + "\n";
        text += std::string(" Id   ") + "|" + " Name             " + "|" + " Price " + "|" + "\n";
        for (VendingMachineDrink drink : m_drinks)
        {
            std::ostringstream stringBuilder;
            stringBuilder << std::string(" ") + std::to_string(drink.GetId()) + std::string(4 - std::to_string(drink.GetId()).length(), ' ') + " " + "|";
            stringBuilder << std::string(" ") + drink.GetName() + std::string(16 - drink.GetName().length(), ' ') + " " + "|";
            stringBuilder << std::string(" ") + "$" + std::to_string(drink.GetPrice()) + std::string(4 - std::to_string(drink.GetPrice()).length(), ' ') + " " + "|";
            stringBuilder << std::string("\n");
            text += stringBuilder.str();
        }
        m_logger->LogInformation(text);
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}
void VendingMachine::AddMoney(int32_t money)
{
    if (m_state == VENDINGMACHINESTATE_WAITING || m_state == VENDINGMACHINESTATE_ACCEPTINGPAYMENT)
    {
        if (m_state == VENDINGMACHINESTATE_WAITING)
            m_state = VENDINGMACHINESTATE_ACCEPTINGPAYMENT;
        m_money += money;
        m_logger->LogInformation(std::string("$") + std::to_string(money) + " accepted." + "\n");
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}
void VendingMachine::Abort()
{
    if (m_state == VENDINGMACHINESTATE_WAITING)
        return;
    else if (m_state == VENDINGMACHINESTATE_ACCEPTINGPAYMENT)
    {
        m_logger->LogInformation(std::string("$") + std::to_string(m_money) + " is your money change." + "\n");
        m_state = VENDINGMACHINESTATE_WAITING;
        m_money = 0;
    }
    else if (m_state == VENDINGMACHINESTATE_VALIDATINGORDER)
    {
        m_logger->LogInformation(std::string("$") + std::to_string(m_money) + " is your money change." + "\n");
        m_state = VENDINGMACHINESTATE_WAITING;
        m_selectedDrink = VendingMachineDrink();
        m_money = 0;
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}
void VendingMachine::SelectDrink(int32_t drinkId)
{
    if (m_state == VENDINGMACHINESTATE_ACCEPTINGPAYMENT)
    {
        bool drinkIsFound = false;
        for (VendingMachineDrink drink : m_drinks)
            if (drink.GetId() == drinkId)
            {
                drinkIsFound = true;
                m_selectedDrink = drink;
                m_logger->LogInformation(std::string("The drink you ordered has been found.") + "\n");
                break;
            }

        if (drinkIsFound && ValidatePayment())
            m_state = VENDINGMACHINESTATE_VALIDATINGORDER;
        else if (drinkIsFound)
            m_logger->LogInformation(std::string("You do not have enough money to purchase this drink. Add money or try selecting another one.") + "\n");
        else
            m_logger->LogInformation(std::string("The drink you ordered has not been found. Try another one.") + "\n");
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}
void VendingMachine::Confirm()
{
    if (m_state == VENDINGMACHINESTATE_VALIDATINGORDER)
    {
        m_state = VENDINGMACHINESTATE_COOKING;
        Cook();
        m_state = VENDINGMACHINESTATE_WAITING;
        m_logger->LogInformation(std::string("$") + std::to_string(m_money - m_selectedDrink.GetPrice()) + " is your money change." + "\n");
        m_selectedDrink = VendingMachineDrink();
        m_money = 0;
    }
    else
        m_logger->LogInformation(std::string("The machine is in an invalid state for this action.") + "\n");
}
