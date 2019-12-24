#include "Automata.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK};
static vector<string> menu = {
	"Espresso",
	"Americano",
	"Mocachino",
	"Cappuccino",
	"Hot chocolate",
	"Cocoa" };
static vector<int> prices = { 35, 30, 20, 35, 30, 25 };
static vector<string> typeOfState = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };

Automata::Automata()
{
	balance = 0;
	state = OFF;
	drink = -1;
};

bool Automata::on() 
{
	if (state == WAIT) 
		return false;

	state = WAIT;
	cout << "The coffee automat is ON! ^_^";
	cout << endl;
	return true;
}

bool Automata::off() 
{
	if (state == OFF) 
		return false;

	state = OFF;
	cout << "The coffee automat turns OFF" << endl;
	return true;
}

bool Automata::coin(int coins) 
{
	if (state == WAIT || state == ACCEPT) 
	{
		balance += coins;
		state = ACCEPT;

		return true;
	}
	else 
	{
		return false;
	}
}

bool Automata::printMenu() 
{
	if (state == OFF) 
		return false;

	cout << "~~~~~Menu~~~~~" << endl;
	for (int i = 0; i < menu.size(); i++)
		cout << i << " " << menu[i] << " - " << prices[i] << endl;
	cout << endl;
	return true;
}

string Automata::printState() 
{
	cout << "Current state = " << typeOfState[state];
	cout << endl;

	return typeOfState[state];
}

bool Automata::choice(int typeOfDrink) 
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

bool Automata::check() 
{
	if (state == OFF) 
		return false;

	else 
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


bool Automata::cancel() 
{
	if (state == OFF) 
		return false;

	else 
		if (state == WAIT || state == OFF)
	{
		cout << "ERROR" << endl;

		return false;
	}

	state = WAIT;
	drink = -1;

	return true;
}

bool Automata::cook()
{
	if (state == OFF)
		return false;
	if (state == CHECK)
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

bool Automata::finish() 
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