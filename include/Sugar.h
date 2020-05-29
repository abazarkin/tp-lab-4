//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_SUGAR_H
#define TASK1_SUGAR_H


#include "CondimentDecorator.h"
#include "Beverage.h"

class Sugar : public CondimentDecorator{
protected:
    Beverage* beverage;
    unsigned int val;
public:
    explicit Sugar(Beverage* beverage, unsigned int val){
        this->beverage = beverage;
        this->val = val;
    }

    virtual string getDescription(){
        return beverage->getDescription() + " + sugar";
    }

    virtual unsigned int getCost(){
        return beverage->getCost() + val;
    }
};


#endif //TASK1_SUGAR_H
