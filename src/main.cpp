//
//  main.cpp
//  Shtanyuk4
//
//  Created by Коля on 12/01/2020.
//  Copyright © 2020 Коля. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Automata.hpp"
//#inlcude <string>
int main(int argc, const char * argv[]) {
    // insert code here...
    Automata a;
    if (a.on() == WAIT)
        std::cout << "Вас приветствует бесполезная машина по продаже напитков, от которых у вас потом начнется гастрит!\n";
    else
    {
        std::cout<<"Чот случилось :(\n";
        exit(0);
    }
    std::cout<<"Меню:\n";
    std::cout<<a.printMenu();
    int money, choice;
    while (true)
    {
        std::cout<<"Баланс: $"<<a.printBalance()<<"\n";
        bool flag = false;
        while (!flag)
        {
            std::cout<<"Внесите деньги (-1, чтобы завершить обслуживание): ";
            std::cin>>money;
            if (money<0)
            {
                a.off();
                exit(0);
            }
            if (a.coin(money) == ACCEPT)
                std::cout<<"Принято! \n";
            else
            {
                std::cout<<"Чот случилось, но деньги мы оставим себе. Спасибо и всего вам самого доброго! \n";
                exit(0);
            }
            std::cout<<"Меню:\n";
            std::cout<<a.printMenu();
            std::cout<<"Сделайте выбор (-1, чтобы завершить обслуживание): ";
            std::cin>>choice;
            if (choice<0)
            {
                a.off();
                exit(0);
            }
            a.choice(--choice);
            if (!a.check())
                std::cout<<"Недостаточно денег! (у вас $" + std::to_string(a.printBalance()) + ")\n";
            else
                flag = true;
        }
        if (a.cook())
        {
            std::cout<<"Приготовлено!\n";
            a.finish();
        }
        else
        {
            std::cout<<"Чот случилось :(";
            exit (0);
        }
    }
    return 0;
}
