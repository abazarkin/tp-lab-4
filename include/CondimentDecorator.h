//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_CONDIMENTDECORATOR_H
#define TASK1_CONDIMENTDECORATOR_H

#include "Beverage.h"

class CondimentDecorator : public Beverage{
public:
    virtual string getDescription() = 0;
};


#endif //TASK1_CONDIMENTDECORATOR_H
