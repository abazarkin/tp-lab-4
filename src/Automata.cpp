#include "Automata.h"
#include <fstream>
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
		cash = 0;
		std::cout << "Automat is ready for working" << std::endl;
	}
	else
		return;
}

void Automata::off()
{
	if (state == WAIT)
		state = OFF;
	else
		return;
}

void Automata::coin(int cost)
{
	if (state == WAIT || state == ACCEPT)
		state = ACCEPT;
	else
		return;
	if (cost < 0)
	{
		std::cout << "Error";
		return;
	}
	else
		cash += cost;
}

void Automata::getMenu()
{
	int len = menu.size();
	for (int i = 0; i < len; i++)
	{
		std::cout << i+1 << ". " << menu[i] << " --- " << prices[i] << std::endl;
	}
}

void Automata::getState()
{
	switch (state)
	{
	case OFF:
		std::cout << "OFF";

	case WAIT:
		std::cout << "WAIT";

	case ACCEPT:
		std::cout << "ACCEPT";

	case CHECK:
		std::cout << "CHECK";

	case COOK:
		std::cout << "COOK";
	}
}

void Automata::choice(int ch)
{
	if (state == OFF)
		return;
	else
	{
		check(ch);
	}
}

void Automata::check(int ch)
{
	if (state == ACCEPT)
		state = CHECK;
	else
		return;
	std::cout << "Checking.." << std::endl;
	if (prices[ch - 1] <= cash)
	{
		std::cout << "Checked." << std::endl;
		cash -= prices[ch - 1];
		std::cout << "Your " << menu[ch - 1] << " is being cooked \n";
		cook();
	}
	else
	{
		std::cout << "You have not enough money \n";
		cancel();
	}
}

void Automata::cook()
{
	if (state == CHECK)
		state = COOK;
	std::cout << "Waiting.." << std::endl;
	finish();
}

int Automata::finish()
{
	std::cout << "Your drink is ready. Take it!\n" << std::endl;
	state = WAIT;
	std::cout << "Take your money\n";
	int money = cash;
	return money;
}

void Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		std::cout << "Operation is cancelled";
	}
	else
		std::cout << "Error";
}

