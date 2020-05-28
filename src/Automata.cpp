#include "Automata.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

std::string Automata::state_description[] = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK" };

Automata::Automata(std::vector<Drink> storage)
{
	menu.resize(storage.size());
	for (int i = 0; i < storage.size(); i++)
	{
		menu[i] = storage[i];
	}
}

void Automata::on() 
{
	if (state == OFF)
	{
		state = WAIT;
	}
}

void Automata::off() 
{
	if (state == WAIT)
	{
		state = OFF;
	}
}

std::string Automata::coin(int cash)
{
	if (this->state != WAIT && this->state != ACCEPT)
	{
		return "";
	}
	this->state = ACCEPT;
	this->cash += cash;
	return ("Current balance: " + std::to_string(this->cash) + "\n");
}

std::string Automata::printMenu()
{
	if (state == OFF)
	{
		return "";
	}
	std::string ans = "";
	for (int i = 0; i < menu.size(); i++)
	{
		ans += this->menu[i].name + " costs " + std::to_string(this->menu[i].price) + "\n";
	}
	return ans;
}

std::string Automata::printState()
{
	return (state_description[state]);
}

std::string Automata::choice(std::string the_chosen_one)
{
	if (state != ACCEPT)
	{
		return "";
	}
	this->state = CHECK;
	this->the_chosen_one = the_chosen_one;
	return ("You wish to cook " + the_chosen_one + "\n");
}

std::string Automata::cancel()
{
	if (state != CHECK && state != ACCEPT)
	{
		return "";
	}
	std::string ans = "";
	ans += "Your money: " + std::to_string(this->cash) + "\n";
	this->cash = 0;
	state = WAIT;
	return ans;
}

bool Automata::check(std::string the_chosen_one)
{
	if (state != CHECK)
	{
		return false;
	}
	for (int i = 0; i < this->menu.size(); i++)
	{
		if (this->menu[i].name == the_chosen_one
			&& this->cash >= this->menu[i].price)
		{
			return true;
		}
	}
	return false;
}

std::string Automata::cook()
{
	if (state != CHECK)
	{
		return "";
	}
	if (check(this->the_chosen_one))
	{
		for (int i = 0; i < this->menu.size(); i++)
		{
			if (this->menu[i].name == this->the_chosen_one)
			{
				cash -= this->menu[i].price;
				break;
			}
		}
		this->state = COOK;
		//brbrbrbr
		//bulpbulp
		//pshhh
		return this->finish();
	}
	else
	{
		return "Operation is invalid\n";
	}
}

std::string Automata::finish() 
{
	if (state != COOK)
	{
		return "";
	}
	std::string ans = "Your drink is ready\nYour change: " + std::to_string(this->cash) + "\n";
	this->cash = 0;
	state = WAIT;
	return ans;
}