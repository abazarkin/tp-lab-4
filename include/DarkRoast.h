//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_DARKROAST_H
#define TASK1_DARKROAST_H


#include "Beverage.h"

class DarkRoast : public Beverage {
    virtual int getCost(){
        return cost;
    }

public:
    explicit DarkRoast(int price){
        description = "Dark roast";
        cost = price;
    }
};


#endif //TASK1_DARKROAST_H
