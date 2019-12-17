//
// Created by Yakhtin Leonid on 17.12.2019.
//

#ifndef LAB_AUTOMATA_H
#define LAB_AUTOMATA_H

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

struct Drink{
    string name;
    int price;
	
	Drink(string _name, int _price) {
		name = _name;
		price = _price;
	}
};

static enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};


class Automata {
	static vector<string>STATE_DESCRIPTION;
	static vector<Drink> menu;
    
	int cash, state, drink_for_prep;

	bool check(int index);
	void finish();
public:
    Automata();
    void on();
    void off();
    bool coin(int coins);
    void printMenu(std::ostream& out);
	string getMenu();
    //void printState(std::ostream& out);
	string printState();
	int getCash();
    bool choice(int index);
    void cancel();
    bool cook();
};


#endif //LAB_AUTOMATA_H
