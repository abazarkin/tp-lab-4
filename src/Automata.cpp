#include "Automata.h"


static enum STATES {OFF = 0, WAIT, ACCEPT, CHECK, COOK} s;
static vector<string> menu = 
{
	"Espresso",
	"Americano",
	"Mocachino",
	"Cappuccino",
	"Hot chocolate",
	"Cocoa" 
};
static vector<unsigned int> prices = { 30, 30, 35, 40, 40, 35 };
static string typeOfState[] = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };

Automata::Automata()
{
	balance = 0;
	state = OFF;
	drink = -1;
};

bool Automata::ON() 
{
	if (state != OFF) 
		return false;

	state = WAIT;
	cout << "The coffee automat is ON! ^_^";
	cout << endl;

	return true;
}

bool Automata::OFF() 
{
	if (state == OFF) 
		return false;

	state = OFF;
	cout << "The coffee automat turns OFF" << endl;
	return true;
}

bool Automata::MENU()
{
	if (state == OFF)
		return false;

	cout << "~~~~~Menu~~~~~" << endl;
	for (int i = 0; i < menu.size(); i++)
		cout << i << " " << menu[i] << " - " << prices[i] << endl;
	cout << endl;
	return true;
}

bool Automata::COOK()
{
	if (state == OFF)
		return false;

	if (state == CHECK && balance - prices[drink] >= 0)
	{
		state = COOK;

		processing();

		balance -= prices[drink];
		cout << "Enjoy your drink! <3" << endl;
		return true;
	}
	else
	{
		cout << "ERROR" << endl;
		return false;
	}
}

bool Automata::CHECK()
{
	if (state == OFF)
		return false;
	
	if (state == CHECK)
	{
		if (balance >= prices[drink])
			return true;
		else
		{
			cout << "Sorry, but you don't have enough funds :(" << endl;
			return false;
		}
	}
	else
	{
		cout << "ERROR" << endl;
		return false;
	}
}

bool Automata::CANCEL()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		drink = -1;
		return true;
	}

	else
		return false;
}

bool Automata::FINISH()
{
	if (state == OFF)
		return false;

	if (state == COOK)
	{
		cout << "Return change" << endl;

		balance = 0;
		drink = -1;
		state = WAIT;

		return true;
	}
	return false;
}

bool Automata::CHOICE(int typeOfDrink)
{
	if (state == ACCEPT)
	{
		drink = typeOfDrink;
		state = CHECK;

		return true;
	}
	else
	{
		return false;
	}
}

bool Automata::cash(unsigned int coins) 
{
	if (state == WAIT || state == ACCEPT) 
	{
		balance += abs(coins);

		if (state == WAIT)
			state = ACCEPT;

		return true;
	}
	else 
	{
		return false;
	}
}

string Automata::curState()
{
	cout << "Current state = " << typeOfState[state];
	cout << endl;

	return typeOfState[state];
}

void Automata::information()
{
	cout << "Current state = " << typeOfState[state] << endl;
	cout << "Amount of coins = " << balance << endl;
	cout << endl;
}

void Automata::processing() 
{
	cout << "Your drink is preparing... Please, wait.";
	cout << endl;
}