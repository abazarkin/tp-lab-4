#include <cstdint>
#include <iostream>
#include <vector>
#include "VendingMachine.h"
#include "VendingMachineDrink.h"
#include "StreamVendingMachineLogger.h"

int32_t main()
{
    std::vector<VendingMachineDrink> drinks =
    {
        VendingMachineDrink(0, 1, "Water"),
        VendingMachineDrink(1, 2, "Tea"),
        VendingMachineDrink(2, 5, "Coffee")
    };
    StreamVendingMachineLogger logger(&std::cout);
    VendingMachine vendingMachine(drinks, &logger);
    vendingMachine.TurnOn();
    vendingMachine.ShowMenu();
    vendingMachine.AddMoney(1);
    vendingMachine.AddMoney(2);
    vendingMachine.AddMoney(5);
    vendingMachine.Abort();
    vendingMachine.TurnOff();

    system("pause");
};
