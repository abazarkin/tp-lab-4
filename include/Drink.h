#ifndef DRINK_H
#define DRINK_H
#include <string>

using namespace std;

class Drink{
    private:
        string drinkName;
        unsigned int price;
    public:
        Drink();
        Drink(string name, int price);
        void setPrice(int price){this->price = price;};
        void setName(string name){this->drinkName = name;};
        int getPrice(){return this->price;};
        string getName(){return this->drinkName;};
};

#endif // DRINK_H
