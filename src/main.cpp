#include "automata.h"
#include <stdio.h>
#include <iostream>
#include <vector>

int main()
{
    
    auto Test_Automata = Automata();
    
    Test_Automata.printState();
    Test_Automata.on();
    Test_Automata.printState();
    Test_Automata.coin(100);
    Test_Automata.printState();
    Test_Automata.printMenu();
    Test_Automata.choice(0);
    Test_Automata.choice(3);
    std::cout << Test_Automata.get_current_cash() << std::endl;
    Test_Automata.choice(10);
    Test_Automata.printState();
    Test_Automata.off();
    
    return 0;
    
}
