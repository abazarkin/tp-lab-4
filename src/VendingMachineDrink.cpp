#include "VendingMachineDrink.h"

VendingMachineDrink::VendingMachineDrink()
{
    m_id = 0;
    m_price = 0;
    m_name = "";
}
VendingMachineDrink::VendingMachineDrink(int32_t id, int32_t price, std::string name)
{
    m_id = id;
    m_price = price;
    m_name = name;
}
