#include <iostream>
#include "coffee_machine.h"
using namespace std;

Automata::Automata()
{
	state = OFF;
	balance = 0;
};

string Automata::on()
{
	if (state == OFF) {
		state = WAIT;
		return "The coffee machine is ON.";
	}
	else
	{
		return "Error: Can't turn the coffee machine ON.";
	}
}

string Automata::off()
{
	if (state == WAIT) {
		state = OFF;
		return "The coffee machine is OFF.";
	}
	else
	{
		return "Error: Can't turn the coffee machine OFF.";
	}
}

float Automata::coin(float money)
{
	state = ACCEPT;
	if (money >= 0)
	{
		balance += money;
		return balance;   // current balance
	}
	else
	{
		return balance;  // if an error occured, the balance doesn't change
	}
}

string Automata::printMenu()
{
	string result = "";
	for (int i = 0; i < 10; i++)
	{
		result += to_string(i) + ". " + menu[i] + " : " + to_string(prices[i]) + "\n";
	}
	return result;
}

string Automata::printState()
{
	string st;
	switch (state)
	{
	case(OFF):
		return "The coffee machine is turned OFF.";

	case(WAIT):
		return "Waiting...";

	case(ACCEPT):
		return "Please pay for your coffee !";

	case(CHECK):
		return "Checking if this type of coffee is available ..";

	case(COOK):
		return "Preparing your coffee :)";
	}
}

string Automata::choice(int typeOfCoffee)
{
	if ((typeOfCoffee > 0) && (typeOfCoffee < 11))
	{
		costOfCoffee = prices[typeOfCoffee - 1];
		state = CHECK;
		return check();
	}
	else
	{
		return "Error: This type of coffee is not available. Please select a type of coffee from the menu or cancel.";
		printMenu();
	}
}

string Automata::check()
{
	if (state == CHECK)
	{

		if (balance < costOfCoffee)
		{
			return to_string(cancel());   // Not enough money
		}
		else
		{
			return cook();    // Perfect! Getting ready to cook !
		}
	}

}

float Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		float change = balance;
		balance = 0;
		return change;    // give the money back
	}
	else
	{
		return 0;
	}
}

string Automata::cook()
{
	if (state == CHECK)
	{
		state = COOK;
		return "Enjoy your coffee :)";
	}
	else
	{
		return "Error";
	}
}

float Automata::finish()
{
	if (state == COOK)
	{
		if (costOfCoffee == balance)
		{
			state = WAIT;
			return 0;
		}
		else
		{
			state = WAIT;
			return balance - costOfCoffee;   // return the change to customer
		}
	}
	else
	{
		cout << "Error" << endl;
	}
}