#include "automata.h"


Automata::Automata()
{
	cash = 0;
	state = OFF;
}

void Automata::on()
{
	if (state == OFF)
	{
		state = WAIT;
		cout << "Automata is on" << endl;
	}
	else
		cout << "The automata is already on" << endl;
}

int Automata::off()
{
	return finish();
	state = OFF;
	cout << "Automata is off" << endl;
}

void Automata::coin(int money)
{
	if (state != OFF)
	{
		state = ACCEPT;
		cash += money;
		cout << "You add: " << money << " rub" << endl;
		cout << "And now your balance: " << cash << " rub" << endl;
	}
	else
		cout << "You can't add coins" << endl;
}

void Automata::printMenu()
{
	if (state != OFF)
	{
		cout << "You can drink:" << endl;
		for (int i = 0; i < menu.size(); i++)
			cout << menu[i] << "  -----  " << prices[i] << " rub" << endl;
	}
	else
		cout << "The automata is off" << endl;
}

void Automata::printState()
{
	cout << "The current state of automata is: " << states[state] << endl;
}

bool Automata::check(int drink)
{
	if (state == ACCEPT || state == CHECK || state == COOK)
	{
		state = CHECK;
		if (cash >= prices[drink])
			return true;
		else
			return false;
	}
	else
		cout << "You can't check it" << endl;
}

int Automata::choice(int drink)
{
	if (state != OFF)
	{
		state = CHECK;
		if ((drink >= 0) && (drink < menu.size()))
		{
			if (check(drink))
				cook(drink);
			else
			{
				cout << "You havn't enough money" << endl;
				return finish();
			}
		}
		else
			cout << "Choose another item" << endl;
	}		
	else
		cout << "You can't choose drinks now" << endl;
	return 0;
}

void Automata::cook(int drink)
{
	if (state == CHECK)
	{
		state = COOK;
		cash -= prices[drink];
		cout << "Enjoy your drink!" << endl;
		cout << "And now your balance: " << cash << " rub" << endl;
	}
	else
		cout << "Something is going wrong" << endl;
}

int Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state == WAIT;
		cout << "The operation is cancelled" << endl;
		return finish();
	}
	else
	{
		cout << "You can't cancel this operation" << endl;
		return 0;
	}
		
}

int Automata::finish()
{
		state = WAIT;
		int money = cash;
		cout << "You can take your money: " << cash << endl;
		cash = 0;
		return money;
}