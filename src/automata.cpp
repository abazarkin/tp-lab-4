#include "automata.h"

#include <string>
#include <vector>
#include <iostream>

Automata::Automata(std::vector<std::string> _menu, std::vector<int> _prises) : menu(_menu), prises(_prises) 
{ 
	state = State::OFF; cash = 0;
	if(menu.size() == 0)
	{
		state = State::NODRINKS;
	}
};


void Automata::coin(int coin)
{
	if (state == State::WAIT || state == State::ACCEPT)
	{
		cash += coin;
		state = State::ACCEPT;
	}
}

void Automata::choise(int n_drink)
{
	if ((state == State::ACCEPT) && (n_drink < menu.size()))
	{
		choosen_drink = n_drink;
		state = State::CHECK;
	}
}

void Automata::cancel()
{
	if (state == State::CHECK || state == State::ACCEPT)
	{
		cash = 0;
		state = State::WAIT;
	}
}

bool Automata::check()
{
	bool ch = false;
	if (state == State::CHECK)
	{
		cash >= prises[choosen_drink] ? ch = true : ch = false;
	}
	
	return ch;
}

void Automata::cook()
{
	if (check())
	{
		state = State::COOK;
	}
}

std::string Automata::finish()
{
	if (state == State::COOK)
	{
		std::string res;
		res += "Done!\n";
		res = res + "Coins inserted - " + std::to_string(cash) + "\n";
		res = res + "Drink          - " + menu[choosen_drink] + "\n";
		res = res + "Prise          - " + std::to_string(prises[choosen_drink]) + "\n";
		res = res + "Cashback       - " + std::to_string(cash - prises[choosen_drink]) + "\n";
		res = res + "Enjoy!";

		state = State::WAIT;
		cash = 0;

		return res;
	}
	return "WRONG STATE";
}

std::string Automata::getState()
{
	switch(state)
	{
	case State::OFF:
		return "OFF";
	case State::WAIT:
		return "WAIT";
	case State::ACCEPT:
		return "ACCEPT";
	case State::CHECK:
		return "CHECK";
	case State::COOK:
		return "COOK";
	case State::NODRINKS:
		return "NODRINKS";

	};
}

std::vector<std::string> Automata::getMenu()
{	
	std::vector<std::string> menu_strings;
	if (state == State::WAIT || state == State::ACCEPT)
	{
		for (int i = 0; i < menu.size(); i++)
		{
			menu_strings.push_back(std::to_string(i) + " drink - " + menu[i] + " - prise " + std::to_string(prises[i]) + "\n");
		}
	}
	return menu_strings;
}