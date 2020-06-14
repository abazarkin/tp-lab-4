#include "Automata.h"

Automata::Automata()
{
	state = aOff;
	this->coins = 0;
}

void Automata::on()
{
	if (state == aOff) {
		this->state = aWait;
		cout << "Hello!" << endl;
	}
}

void Automata::off()
{
	if (this->state == aWait) {
		state = aOff;
		cout << "Bye!" << endl;
	}
}

void Automata::coin(unsigned int currency)
{
	if (this->state == aWait || this->state == aAccept)
	{
		this->coins += currency;
		cout << "Cash:  " << currency << endl;
	}
}

void Automata::cancel()
{
	if (this->state != aOff) {
		this->state = aWait;
		cout << " Return " << coins << " coins" << endl;
		coins = 0;
	}
}

void Automata::choice(unsigned int num)
{
	if (this->state == aWait || this->state == aAccept)
	{
		this->state = aCheck;
		if (check(num) == true)
		{
			this->state = aCook;
			cook(num);
		}
		else
		{
			cancel();
		}

	}
}

bool Automata::check(unsigned int num)
{
	if (this->coins >= this->price[num - 1])
	{
		this->coins -= price[num - 1];
		return true;
	}
	else
	{
		cout << "Not enough cash!" << endl;
		return false;
	}
}

void Automata::cook(unsigned int num)
{
	if ((state == aCheck) & (check(num) == true))
	{
		cout << "Please,wait. Your drink is cooking." << endl;
		this->state = aWait;
		cout << "Ready!Please, take a drink." << endl;
	}
}

int Automata::getCash()
{
	cout << "Get cash  " << this->coins << endl;
	return this->coins;
}