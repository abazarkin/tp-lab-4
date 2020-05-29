#include "Automata.h"
#include <iostream>
#include <string>
//#include <windows.h>

using namespace std;

Automata::Automata()
{
	cash = 0;
	state = OFF;
}

void Automata::on()
{
	if (state == OFF) {
		state = WAIT;
	}
	else
		cout << "Incorrect command. ";
	cout << "Automata turned on" << endl;
	printState();
}

void Automata::off()
{
	if (state == WAIT)
		state = OFF;
	cout << "Automata turned off, goodbye!" << endl;
	printState();
}

unsigned int Automata::coin(unsigned int money)
{
	if ((state == WAIT) || (state == ACCEPT))
	{
		/*unsigned int money;
		cout << "Please, enter amount of money" << endl;
		cin >> money;*/
		cash += money;
		state = ACCEPT;
	}
	cout << "Balance : " << cash << endl;
	return cash;
}

void Automata::printMenu()
{
	cout << "Menu:" << endl;
	for (int i = 0; i < 5; i++)
		cout << menu[i] << " - " << prices[i] << endl;
}

void Automata::printState()
{
	cout << "Current Automata State: " << state_str[state] << endl;
}

void Automata::cancel()
{
	if ((state == ACCEPT) || (state == CHECK))
	{
		state = WAIT;
		cout << "Operation cancelled" << endl;
	}
}


void Automata::choice(unsigned int num)
{
	if ((state == ACCEPT) || (state == WAIT))
	{
		printMenu();
		/*cout << "Please, choose number of drink (from 1 to 5)" << endl;
		int num;
		cin >> num;
		while ((num > 5) || (num < 0)) {
			cout << "Please, choose again from 1 to 5" << endl;
			cin >> num;
		}*/
		num--;
		cout << "You've chosen " << menu[num] << endl;
		state = CHECK;
		cook(num);
	}
}

bool Automata::check(unsigned int num)
{
	state = CHECK;
	if (prices[num] > cash)
	{
		cout << "Not enough money" << endl;
		cancel();
		return false;
	}
	else
	{
		state = COOK;
		cash -= prices[num];
		return true;
	}
}

void Automata::cook(unsigned int num)
{
	if (check(num))
	{
		state = COOK;
		cout << "Your coffee is being prepared, wait 5 sec" << endl;
		for (int i = 1; i < 6; i++)
		{
			cout << i << "..." << endl;
			//Sleep(1000);
		}
		finish();
	}

}

void Automata::finish()
{
	if (state == COOK)
	{
		cout << "You can take your coffee. Thank you!" << endl;
		state = WAIT;
	}
}

unsigned int Automata::change()
{
	if (state == WAIT)
	{
		unsigned int new_change = cash;
		cout << "Your change is " << cash << endl;
		cash = 0;
		return new_change;
	}
}