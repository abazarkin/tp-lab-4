#include <vector>
#include "VendingMachine.h"
#include "VendingMachineDrink.h"
#include "VendingMachineState.h"

VendingMachine::VendingMachine(std::vector<VendingMachineDrink> drinks)
{
    m_drinks = drinks;
    m_state = VENDINGMACHINESTATE_TURNEDOFF;
}

VendingMachineState VendingMachine::GetState() { return m_state; }
