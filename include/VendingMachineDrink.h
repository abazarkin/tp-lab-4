#ifndef _VENDINGMACHINEDRINK_H_
#define _VENDINGMACHINEDRINK_H_

#include <cstdint>
#include <string>

class VendingMachineDrink
{
private:
    int32_t m_id;
    int32_t m_price;
    std::string m_name;

public:
    VendingMachineDrink();
    VendingMachineDrink(int32_t id, int32_t price, std::string name);

    int32_t GetId() { return m_id; };
    int32_t GetPrice() { return m_price; };
    std::string GetName() { return m_name; }
};

#endif // _VENDINGMACHINEDRINK_H_
