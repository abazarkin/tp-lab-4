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

void Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
		cout << "Automata is off" << endl;
	}
	else
		cout << "You can't off the automata" << endl;
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

void Automata::choice(int drink)
{
	if (state != OFF)
		state = CHECK;
	else
		cout << "You can't choose drinks now" << endl;

	if ((drink >= 0) && (drink < menu.size()))
	{
		if (check(drink))
			cook(drink);
		else
		{
			cout << "You havn't enough money" << endl;
			finish();
		}	
	}
	else
		cout << "Choose another item" << endl;
}

void Automata::cook(int drink)
{
	if (state == CHECK)
	{
		state = COOK;
		cash -= prices[drink];
		cout << "Enjoy your drink!" << endl;
		cout << "And now your balance: " << cash << " rub" << endl;
		finish();
	}
	else
		cout << "Something is going wrong" << endl;
}

void Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state == WAIT;
		cout << "The operation is cancelled" << endl;
		finish();
	}
	else
		cout << "You can't cancel this operation" << endl;
}

void Automata::finish()
{
		state = WAIT;
		cout << "You can take your money: " << cash << endl;
		cash = 0;
}