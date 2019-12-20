#ifndef _VENDINGMACHINE_H_
#define _VENDINGMACHINE_H_

#include <cstdint>
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
    int32_t m_money;

public:
    VendingMachine(std::vector<VendingMachineDrink> drinks, VendingMachineLogger *logger);

    VendingMachineState GetState();
    int32_t GetMoney();

    void TurnOn();
    void TurnOff();

    void ShowMenu();
    void AddMoney(int32_t money);
    void Abort();
};

#endif // _VENDINGMACHINE_H_
