#include "VendingMachine.h"
#include "VendingMachineState.h"

VendingMachine::VendingMachine()
{
    m_state = VENDINGMACHINESTATE_TURNEDOFF;
}

VendingMachineState VendingMachine::GetState() { return m_state; }
