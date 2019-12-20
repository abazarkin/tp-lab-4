#ifndef _VENDINGMACHINE_H_
#define _VENDINGMACHINE_H_

#include "VendingMachineState.h"

class VendingMachine
{
private:
    VendingMachineState m_state;

public:
    VendingMachine();

    VendingMachineState GetState();
};

#endif // _VENDINGMACHINE_H_
