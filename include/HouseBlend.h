//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_HOUSEBLEND_H
#define TASK1_HOUSEBLEND_H


#include "Beverage.h"

class HouseBlend : public Beverage {
public:
    explicit HouseBlend(int price){
        description = "House blend";
        cost = price;
    }
    virtual int getCost(){
        return cost;
    }
};


#endif //TASK1_HOUSEBLEND_H
