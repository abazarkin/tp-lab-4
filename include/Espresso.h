//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_ESPRESSO_H
#define TASK1_ESPRESSO_H


#include "Beverage.h"

class Espresso : public Beverage {
public:
    explicit Espresso(unsigned int price){
        description = "Espresso";
        cost = price;
    }
    virtual unsigned int getCost(){
        return cost;
    }
};


#endif //TASK1_ESPRESSO_H
