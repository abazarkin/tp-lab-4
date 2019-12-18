//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_MOCHA_H
#define TASK1_MOCHA_H


#include "CondimentDecorator.h"
#include "Beverage.h"


class Mocha : public CondimentDecorator{
protected:
    Beverage* beverage;
    unsigned int val;
public:
    explicit Mocha(Beverage* beverage, unsigned int val){
        this->beverage = beverage;
        this->val = val;
    }

    virtual string getDescription(){
        return beverage->getDescription() + " + mocha";
    }

    virtual unsigned int getCost(){
        return beverage->getCost() + val;
    }
};


#endif //TASK1_MOCHA_H
