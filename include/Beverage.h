//
// Created by Илья on 017 17.12.19.
//

#ifndef TASK1_BEVERAGE_H
#define TASK1_BEVERAGE_H

#include <string>
using std::string;


class Beverage{
protected:
    string description;
    unsigned int cost;
public:
    virtual string getDescription(){
        return description;
    }
    virtual unsigned int getCost() = 0;
};
#endif //TASK1_BEVERAGE_H
