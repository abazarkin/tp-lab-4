#ifndef AutomataH
#define AutomataH

#include <iostream>

using namespace std;

class Automata 
{
private:
	int state;
	unsigned int balance;
	int drink;

public:
	Automata();

	bool on();

	bool off();

	bool coin(int coins);

	bool printMenu();

	string printState();

	bool choice(int typeOfDrink);

	bool check();

	bool cancel();

	bool cook();

	bool finish();

	void information();

	void processing();
};

#endif