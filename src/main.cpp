#include <iostream>
#include "Automata.h"

int main() {

    Automata automata = Automata();

    if (OFF == automata.getState()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }


    return 0;
}
