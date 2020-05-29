#include "Automata.h"

int main(int argc, char* argv[]) {

    Automata obj;
    obj.printState();
    std::cout << std::endl; 

    //std::cout << "OFF |"; obj.off(); obj.printState();
    //std::cout << "ON  |"; obj.on(); obj.printState();
    std::cout << "ON  |"; obj.on(); obj.printState();
    //obj.printMenu();
    //std::cout << "OFF |"; obj.off(); obj.printState();
    //obj.printMenu();

    obj.printMenu();
    obj.coin(10);
    obj.printInform();
    obj.coin(5);
    obj.printInform();

    obj.choice(1);
    obj.printInform();
    obj.check();
    obj.printInform();
    obj.cancel();
    obj.printInform();

    obj.coin(100);
    obj.printMenu();
    obj.choice(2);
    obj.printInform();
    obj.check();
    obj.printInform();
    obj.cook();
    obj.printInform();

    obj.finish();
    obj.printInform();


    return 0;
}
