#include <cstdint>
#include <vector>
#include <sstream>
#include "VendingMachine.h"
#include "VendingMachineDrink.h"
#include "VendingMachineLogger.h"
#include "VendingMachineState.h"

using namespace std::string_literals;

VendingMachine::VendingMachine(std::vector<VendingMachineDrink> drinks, VendingMachineLogger *logger)
{
    m_drinks = drinks;
    m_logger = logger;
    m_state = VENDINGMACHINESTATE_TURNEDOFF;
    m_selectedDrink = VendingMachineDrink(0, 0, ""s);
    m_money = 0;
}

bool VendingMachine::ValidatePayment() { return m_money >= m_selectedDrink.GetPrice(); }

VendingMachineState VendingMachine::GetState() { return m_state; }
VendingMachineDrink VendingMachine::GetSelectedDrink() { return m_selectedDrink; }
int32_t VendingMachine::GetMoney() { return m_money; }

void VendingMachine::TurnOn()
{
    if (m_state == VENDINGMACHINESTATE_TURNEDOFF)
    {
        m_state = VENDINGMACHINESTATE_WAITING;
        m_logger->LogInformation("The machine has been turned on.");
    }
    else
        m_logger->LogInformation("The machine is in an invalid state for this action.");
}
void VendingMachine::TurnOff()
{
    if (m_state == VENDINGMACHINESTATE_WAITING)
    {
        m_state = VENDINGMACHINESTATE_TURNEDOFF;
        m_logger->LogInformation("The machine has been turned off.");
    }
    else
        m_logger->LogInformation("The machine is in an invalid state for this action.");
}

void VendingMachine::ShowMenu()
{
    if (m_state != VENDINGMACHINESTATE_TURNEDOFF)
    {
        std::string text;
        text += "Menu:"s + "\n"s;
        text += " Id   "s + "|"s + " Name             "s + "|"s + " Price "s + "|"s + "\n"s;
        for (VendingMachineDrink drink : m_drinks)
        {
            std::ostringstream stringBuilder;
            stringBuilder << " "s + std::to_string(drink.GetId()) + std::string(4 - std::to_string(drink.GetId()).length(), ' ') + " "s + "|"s;
            stringBuilder << " "s + drink.GetName() + std::string(16 - drink.GetName().length(), ' ') + " "s + "|"s;
            stringBuilder << " "s + "$"s + std::to_string(drink.GetPrice()) + std::string(4 - std::to_string(drink.GetPrice()).length(), ' ') + " "s + "|"s;
            stringBuilder << "\n"s;
            text += stringBuilder.str();
        }
        m_logger->LogInformation(text);
    }
    else
        m_logger->LogInformation("The machine is in an invalid state for this action.");
}
void VendingMachine::AddMoney(int32_t money)
{
    if (m_state == VENDINGMACHINESTATE_WAITING || m_state == VENDINGMACHINESTATE_ACCEPTINGPAYMENT)
    {
        if (m_state == VENDINGMACHINESTATE_WAITING)
            m_state = VENDINGMACHINESTATE_ACCEPTINGPAYMENT;
        m_money += money;
        m_logger->LogInformation("$"s + std::to_string(money) + " accepted."s + "\n"s);
    }
    else
        m_logger->LogInformation("The machine is in an invalid state for this action.");
}
void VendingMachine::Abort()
{
    if (m_state == VENDINGMACHINESTATE_WAITING)
        return;
    else if (m_state == VENDINGMACHINESTATE_ACCEPTINGPAYMENT)
    {
        m_state = VENDINGMACHINESTATE_WAITING;
        m_money = 0;
        m_logger->LogInformation("$"s + std::to_string(m_money) + " is your money change."s + "\n"s);
    }
#warning Handle another states here.
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
                m_logger->LogInformation("The drink you ordered has been found.");
                break;
            }

        if (drinkIsFound && ValidatePayment())
            m_state = VENDINGMACHINESTATE_VALIDATINGORDER;
        if (drinkIsFound)
            m_logger->LogInformation("You do not have enough money to purchase this drink. Add money or try selecting another one.");
        else
            m_logger->LogInformation("The drink you ordered has not been found. Try another one.");
    }
    else
        m_logger->LogInformation("The machine is in an invalid state for this action.");
}
