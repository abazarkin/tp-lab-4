#include "Drink.h"

Drink::Drink(){
    this->drinkName = "SmplName";
    this->price = 0;
}

Drink::Drink(string name, int price)
{
    this->drinkName = name;
    this->price = price;
}
