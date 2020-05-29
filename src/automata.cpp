#include "automata.h"

Automata::Automata()
{
    
    current_state = States::OFF;
    cash = 0;
    
}

void Automata::on()
{
    
    if (current_state == States::OFF)
    {
        current_state = States::WAIT;
        std::cout << "The Automata is on! Please, wait." << std::endl;
    }
    
    else
    {
        std::cout << "The Automata is already on! Do not turn it on again!" << std::endl;
    }
    
}

void Automata::off()
{
    
    if (current_state == States::WAIT)
    {
        current_state = States::OFF;
        std::cout << "The machine is off! Thank you for using our service!" << std::endl;
    }
    
    else
    {
        std::cout << "You can not turn off the machine during its operation!" << std::endl;
    }
    
}

void Automata::coin(int value)
{
    if (current_state == States::ACCEPT || current_state == States::WAIT)
        
    {
        cash += value;
        current_state = States::ACCEPT;
        std::cout << value << " rub successfully credited! Make a purchase!" << std::endl;
    }
    
    else
    {
        std::cout << "Do not deposit money during this operation!" << std::endl;
    }

}

void Automata::printMenu()
{
    
    for (size_t i = 0; i < menu.size(); i++)
    {
       std::cout << menu[i] << " - " << prices[i] << " rub" << std::endl;
    }
    
}

void Automata::printState()
{
    
    std::cout << state_labels[current_state] << std::endl;
    
}

void Automata::choice(int drink)
{
    
    if (drink <= menu.size() && drink >= 1)
    {
        
       if (check(drink))
       {
           cook(drink);
           finish();
       }
        
       else
       {
           std::cout <<  "Not enough money to buy this drink." << std::endl;
           cancel();
       }
        
    }
    
    else
    {
        std::cout << "Invalid drink number selected!" << std::endl;
    }
    
}

bool Automata::check(int drink)
{
    
    current_state = States::CHECK;
    
    if (prices[drink - 1] <= cash)
    {
        return true;
    }
    
    else
    {
        return false;
    }
    
}

void Automata::cancel()
{
    
    if (current_state != States::OFF)
    {
        current_state = States::WAIT;
        std::cout << "This action has been canceled!" << std::endl;
    }
    
    else
    {
        std::cout << "The machine is off!" << std::endl;
    }

}

void Automata::cook(int drink)
{
    
    current_state = States::COOK;
    cash -= prices[drink - 1];
    std::cout << "Wait, the drink is getting ready!" << std::endl;
    std::cout << "Hurrah! The drink is ready! Take it!" << std::endl;
    
}

void Automata::finish()
{
    
    current_state = States::WAIT;
    
}

States Automata::get_current_state()
{
    
    return current_state;
    
}

int Automata::get_current_cash()

{
    
    return cash;
    
}
