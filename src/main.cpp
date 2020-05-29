#include <iostream>
#include "Automata.h"

int main() {
    Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(30);
    Coffee.printMenu();
    Coffee.cancel();
    Coffee.choice(2);

    return 0;
}