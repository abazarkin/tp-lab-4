#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>

class Automata {
private:
    unsigned int cash;
    int state;
    int ans;

public:
    Automata();
    ~Automata();
    bool on();
    bool off();
    bool coin(unsigned int coins);
    bool printMenu();
    std::string printState() const;
    bool choice(int local_ans);
    bool check();
    bool cancel();
    bool cook();
    bool finish();

    void printInform() const;
    void processing();
};



#endif // AUTOMATA_H