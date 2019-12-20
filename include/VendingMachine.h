#ifndef _VENDINGMACHINE_H_
#define _VENDINGMACHINE_H_

#include <vector>
#include "VendingMachineDrink.h"
#include "VendingMachineLogger.h"
#include "VendingMachineState.h"

class VendingMachine
{
private:
    std::vector<VendingMachineDrink> m_drinks;
    VendingMachineLogger *m_logger;
    VendingMachineState m_state;

public:
    VendingMachine(std::vector<VendingMachineDrink> drinks, VendingMachineLogger *logger);

    VendingMachineState GetState();

    void TurnOn();
    void TurnOff();
};

#endif // _VENDINGMACHINE_H_
