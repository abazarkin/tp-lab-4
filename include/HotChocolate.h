//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_HOTCHOCOLATE_H
#define TASK1_HOTCHOCOLATE_H


#include "Beverage.h"

class HotChocolate : public Beverage {
    virtual unsigned int getCost(){
        return cost;
    }

public:
    explicit HotChocolate(unsigned int price){
        description = "Hot chocolate";
        cost = price;
    }
};


#endif //TASK1_HOTCHOCOLATE_H
