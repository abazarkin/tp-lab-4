#include <vector>
#include "VendingMachine.h"
#include "VendingMachineDrink.h"
#include "VendingMachineLogger.h"
#include "VendingMachineState.h"

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
