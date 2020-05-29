//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_HOUSEBLEND_H
#define TASK1_HOUSEBLEND_H


#include "Beverage.h"

class HouseBlend : public Beverage {
public:
    explicit HouseBlend(unsigned int price){
        description = "House blend";
        cost = price;
    }
    virtual unsigned int getCost(){
        return cost;
    }
};


#endif //TASK1_HOUSEBLEND_H
