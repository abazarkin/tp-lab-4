#include "Automata.h"
#include <iostream>
using namespace std;


Automata::Automata() 
{
	Money = 0;
	CurrentState = OFF;
}

void Automata::on() 
{
	if (CurrentState == OFF)
	{
		CurrentState = WAIT;
		cout << "I am ready :)" << endl;
	}
}

void Automata::off() 
{
	if (CurrentState == WAIT)
	{
		CurrentState = OFF;
		cout << "Good Bye :(" << endl;
	}
}

int Automata::coin(unsigned int sum) 
{
	if (CurrentState == WAIT || CurrentState == ACCEPT)
	{
		CurrentState = ACCEPT;
		Money = Money + sum;
		cout << "Your balance: " << Money << endl;
	}
	else
	{
		cout << "Error" << endl;
	}
	return Money;
}

void Automata::printMenu() 
{
	cout << "Our Menu:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << ")" << Menu[i] << "  Price:" << Prices[i] << endl;
	}
}

void Automata::check(const int NumOfDrink) {
	if (CurrentState == CHECK)
	{
		if (Prices[NumOfDrink] <= Money) 
		{
			Money = Money - Prices[NumOfDrink];
			cout << "Successful! Now I will make your drink! :)" << endl;
			cook();
		}
		else 
		{
			cout << "Please, deposit more money" << endl;
		}
	}
	else 
	{
		std::cout << "Error" << endl;
	}
}

void Automata::printState() {
	switch (CurrentState)
	{
	case OFF:
		cout << "Current State: OFF" << endl;
		break;
	case WAIT:
		cout << "Current State: WAIT" << endl;
		break;
	case ACCEPT:
		cout << "Current State: ACCEPT" << endl;
		break;
	case CHECK:
		cout << "Current State: CHECK" << endl;
		break;
	case COOK:
		cout << "Current State: COOK" << endl;
		break;
	}
}

string Automata::choice(string mychoice) 
{
	if (CurrentState == ACCEPT) 
	{
		for (int i = 0; i < 6; i++) 
		{
			if (mychoice == Menu[i])
			{
				CurrentState = CHECK;
				check(i);
			}
		}
	}
	else 
	{
		cout << "Error" << endl;
	}
	return mychoice;
}


void Automata::cancel() {
	if (CurrentState == CHECK || CurrentState == ACCEPT)
	{
		CurrentState = WAIT;
		cout << "Please, take your money" << Money << endl;
		Money = 0;
	}
	else
	{
		cout << "Error" << endl;
	}
}

void Automata::cook() {
	if (CurrentState == CHECK)
	{
		CurrentState = COOK;
		cout << "The drink will be ready in 30 seconds" << endl;
		finish();
	}
	else
	{
		cout << "Error" << endl;
	}
}

void Automata::finish() {
	if (CurrentState == COOK)
	{
		CurrentState = WAIT;
		cout << "Please, take your drink!" << endl;
		off();
	}
	else
	{
		cout << "Error" << endl;
	}
}