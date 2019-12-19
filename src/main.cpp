#include <iostream>

using namespace std;

#include "Automata.h"

int main()
{
    int inp;
    Automata aut;
    aut.on();
    aut.coin(50);
    aut.choice(0);
    aut.finish();
    aut.off();
    return 0;
}
