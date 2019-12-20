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
}

VendingMachineState VendingMachine::GetState() { return m_state; }

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
