//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_HOTCHOCOLATE_H
#define TASK1_HOTCHOCOLATE_H


#include "Beverage.h"

class HotChocolate : public Beverage {
    virtual int getCost(){
        return cost;
    }

public:
    explicit HotChocolate(int price){
        description = "Hot chocolate";
        cost = price;
    }
};


#endif //TASK1_HOTCHOCOLATE_H
