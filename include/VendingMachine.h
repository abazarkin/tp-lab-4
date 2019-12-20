#ifndef _VENDINGMACHINE_H_
#define _VENDINGMACHINE_H_

#include <vector>
#include "VendingMachineDrink.h"
#include "VendingMachineState.h"

class VendingMachine
{
private:
    std::vector<VendingMachineDrink> m_drinks;
    VendingMachineState m_state;

public:
    VendingMachine(std::vector<VendingMachineDrink> drinks);

    VendingMachineState GetState();
};

#endif // _VENDINGMACHINE_H_
