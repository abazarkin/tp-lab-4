#ifndef AutomataH
#define AutomataH

#include <vector>
#include <string>
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

	bool ON();

	bool OFF();

	bool MENU();

	bool COOK();

	bool CHECK();

	bool CANCEL();

	bool FINISH();

	bool CHOICE(int typeOfDrink);

	bool cash(unsigned int coins);

	string curState() const;

	void information() const;

	void processing();
};
#endif