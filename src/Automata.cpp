//
//  Automata.cpp
//  Shtanyuk4
//
//  Created by Коля on 12/01/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#include "Automata.hpp"
Automata::Automata()
{
    this->state = OFF;
    this->cash = 0;
}

States Automata::on()
{
    if (this->state == OFF)
        state = WAIT;
    return state;
}

States Automata::off()
{
    if (this->state == WAIT)
        this->state = OFF;
    return this->state;
}


std::string Automata::printState()
{
    
    return StatesNames[this->state];
}

States Automata::coin(unsigned int val)
{
    if (this->state != WAIT || this->state != ACCEPT)
        return this->state;
    this->state = ACCEPT;
    this->cash += val;
    return this->state;
}

std::string Automata::printMenu()
{
    std::string rmenu = "";
    for (int i=0; i<this->menu.size(); i++)
        rmenu += this->menu[i] + " — $" + std::to_string(this->prices[i]) + "\n";
    return rmenu;
}

void Automata::choice(unsigned int val)
{
    this->current_choice = val >= this->menu.size() ? -1 : val;
}

bool Automata::check()
{
    this->state = CHECK;
    return this->prices[this->current_choice] <= this->cash;
}

States Automata::cancel()
{
    if (this->state != CHECK && this->state != ACCEPT)
        return this->state;
    this->state = WAIT;
    return this->state;
}

bool Automata::cook()
{
    if (!this->check())
    {
        this->state = WAIT;
        return false;
    }
    this->state = COOK;
    this->cash -= this->prices[this->current_choice];
    return true;
}

States Automata::finish()
{
    if (this->state == COOK)
        this->state = WAIT;
    return this->state;
}
