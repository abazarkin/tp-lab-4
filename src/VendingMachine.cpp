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
