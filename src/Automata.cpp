#include "Automata.h"
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
		std::cout << "Automat is ready for working \n";
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
std::string Automata::getState()
{
	switch (state)
	{
	case OFF:
		return "OFF";

	case WAIT:
		return "WAIT";

	case ACCEPT:
		return "ACCEPT";

	case CHECK:
		return "CHECK";

	case COOK:
		return "COOK";
	default:
		return "NO STATE";
	}
}

int Automata::choice(int ch)
{
	if (state == OFF || ch >= menu.size() || ch <= 0)
		return -1;
	else
	{
		return check(ch);
	}
}

int Automata::check(int ch)
{
	if (state == ACCEPT)
		state = CHECK;
	else
		return -1;
	std::cout << "Checking.." << std::endl;
	if (prices[ch - 1] <= cash)
	{
		std::cout << "Checked." << std::endl;
		cash -= prices[ch - 1];
		std::cout << "Your " << menu[ch - 1] << " is being cooked \n";
		return cash;
	}
	else
	{
		std::cout << "You have not enough money \n";
		return 0;
	}
}

void Automata::cook()
{
	if (state == CHECK)
		state = COOK;
	std::cout << "Waiting.." << std::endl;
}

int Automata::finish()
{
	if (state == COOK)
		state = WAIT;
	else
		return -1;
	int money = cash;
	return money;
}

int Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		std::cout << "Operation is cancelled\n";
		int money = cash;
		return money;
	}
	else
	{
		std::cout << "Error\n";
		return -1;
	}
}

