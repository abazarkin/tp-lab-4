#include "Automata.h"

int main(int argc, char* argv[]) {

    Automata obj;
    obj.printState();

    std::cout << "OFF |"; obj.off(); obj.printState();
    std::cout << "ON  |"; obj.on(); obj.printState();
    std::cout << "ON  |"; obj.on(); obj.printState();
    obj.printMenu();
    std::cout << "OFF |"; obj.off(); obj.printState();
    obj.printMenu();
    

    return 0;
}