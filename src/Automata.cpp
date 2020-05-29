#include "Automata.h"
#include <iostream>

Automata::Automata()
{
	this->state = STATE_OFF;
	this->money = 0;
}

void Automata::on()
{
	int sts = 0; //status
	sts = state == STATE_OFF ? 1 : 0;
	if (sts) {
		this->state = STATE_WAIT;
		std::cout << "Welcome!" << std::endl;
	}
}

void Automata::off()
{
	int sts = 0; //status
	sts = state == STATE_WAIT ? 1 : 0;
	if (sts) {
		this->state = STATE_OFF;
		std::cout << "Have a good day! Goodbye!" << std::endl;
	}
}

void Automata::cancel()
{
	int sts = 0; //status
	sts = state == STATE_OFF ? 1 : 0;
	if (!sts) {
		this->state = STATE_WAIT;
		std::cout << "Return " << money << std::endl;
		money = 0;
	}
}

void Automata::coin(int payment)
{
	int sts = 0; //status
	sts = state == (STATE_WAIT || STATE_ACCEPT) ? 1 : 0;
	if (sts) {
		this->money += payment;
		std::cout << "Payment: " << money << std::endl;
	}
}

void Automata::choice(int product_num)
{
	int sts = 0; //status
	sts = (state == (STATE_WAIT || STATE_ACCEPT)) ? 1 : 0;
	if (sts) {
		this->state = STATE_CHECK;
		if (check(product_num)) {
			this->state = STATE_WORK;
			cook(product_num);

		}
		else cancel();
	}
}

bool Automata::check(int product_num)
{
	if (this->money >= this->price[product_num - 1]) {
		this->money -= price[product_num - 1];
		return true;
	}
	else
	{
		std::cout << "Sorry, not enough money" << std::endl;
		return false;
	}
}

void Automata::cook(int product_num) 
{
	int sts = 0; //status
	sts = (state == STATE_WORK ) ? 1 : 0;
	if (sts) {
		std::cout << "Please, wait" << std::endl;
		this->state = STATE_WAIT;
		std::cout << "Enjoy your drink!" << std::endl;
	}
}

int Automata::getMoney() 
{
	std::cout << "Money: " << this->money << std::endl;
	return this->money;
}

void Automata::printMenu() {
	std::cout << "Menu" << std::endl;
	std::cout << "Product - Price" << std::endl;
	for (auto i = 0; i < menu.size(); i++) {
		std::cout << menu[i].first << " = " << menu[i].second << std::endl;
	}
}

void Automata::finish()
{
	this->state = STATE_WAIT;
}