#include "automata.h"

Automata::Automata()
{
	chosenNum = -1;
	cash = 0;
	key = 1234;
	state = OFF;
	m.n = 0;
	m.dishes = NULL;
	m.prices = NULL;
	setMenu();
}

Automata::~Automata()
{
	delete[] m.dishes;
	delete[] m.prices;
}

states Automata::getState() const
{
	return state;
}

menu Automata::getMenu() const
{
	return m;
}

int Automata::getCash() const
{
	return cash;
}

void Automata::setMenu()
{
	m.n = 4;
	m.dishes = new string[m.n];
	m.prices = new int[m.n];
	m.prices[0] = 40; m.dishes[0] = "coffe1";
	m.prices[1] = 45; m.dishes[1] = "coffe2";
	m.prices[2] = 50; m.dishes[2] = "coffe3";
	m.prices[3] = 60; m.dishes[3] = "coffe4";
}

bool Automata::check()
{
	if (chosenNum == -1) return false;
	return cash >= (m.prices[chosenNum]);
}

returns Automata::cook()
{
	state = COOK;
	cout << "preparing..." << endl;
	state = READY;
	return CORRECT;
}
returns Automata::finish()
{
	if (state == READY)
	{
		cansel();
		return CORRECT;
	}
	return MISTAKE;
}


returns Automata::on()
{
	if (state == OFF)
	{
		if (m.dishes)
		{
			state = WAIT;
		}
		else
		{
			state = ERROR;
		}
		return CORRECT;
	}
	
		return FAIL;
	
}
returns Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
		return CORRECT;
	}
		return MISTAKE;
}

returns Automata::coin(int sum)
{
	if (state == WAIT)
	{
		state = ACCEPT;
	}
	if (state == ACCEPT)
	{
		cash += sum;
		return CORRECT;
	}
	return FAIL;
}
returns Automata::choise(int Num)
{	
	if ((state == ACCEPT))
	{
		if ((Num >= m.n) || (Num < 0))
		{
			return MISTAKE;
		}
		chosenNum = Num;
		if (check())
		{
			cook();
			return CORRECT;
		}
		return MISTAKE;	
	}
	return FAIL;
}

returns Automata::cansel()
{
	if (state == OFF)
	{
		return FAIL;
	}
	cash = 0;
	chosenNum = -1;
	state = WAIT;
	return CORRECT;
}