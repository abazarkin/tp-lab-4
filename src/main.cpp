//
//  main.cpp
//  lab4
//
//  Created by Андрей Журавлев on 02.11.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//


#include <iostream>
#include "Automata.hpp"

std::string str = "1: Water 10 R\n2: Soda 15 R\n3: Green tea 15 R\n4: Black tea 15 R\n5: Espresso 30 R\n6: Latte 45 R\n7: Cappuccino 50 R\n8: Double espresso 60 R\n9: Double latte 75 R\n10: Mocaccino 100 R\n";

int main(int argc, const char * argv[]) {
    Automata aut;
    std::cout << aut.print_state() << std::endl;
//    do {
//        aut.coin(40);
//    } while (aut.get_state() == WAIT);
}
