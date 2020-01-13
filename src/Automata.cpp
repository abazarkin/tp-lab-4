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
    if (state == WAIT)
        state = OFF;
    return state;
}

