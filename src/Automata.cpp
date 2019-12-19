#include "Automata.h"

string Automata::menu[6] = { "Coffee", "Tea", "Milk", "Espresso", "Moka", "Water"};
unsigned Automata::prices[6] = {100, 150, 50, 300, 500, 10};

Automata::Automata() {
	state = OFF;
}

string Automata::on() {
	if (state == OFF) {
		state = WAIT;
		cash = 0;
		return "Automata is: ON;";
	} 
	else 
	{
		return "Automata has been already working;";
	}
	
	
}

string Automata::off() {
	if (state == WAIT) {
		state = OFF;
		cash = 0;
		return "Automata is: OFF;";
	}
	else
	{
		return "Can`t get off the Automata";
	}
}

string Automata::coin(const unsigned cash) {
	if (state == WAIT or state == ACCEPT) {
		state = ACCEPT;
		this->cash += cash;
		return "You deposit " + to_string(cash) + ";\nYour balance: " + to_string(this->cash) + ';';
	} 
	else
	{
		return "Can`t deposit. Try again;";
	}
	
}

string Automata::choiñe(const string drink) {
	for (size_t i = 0; i < 6; i++) {
		if (drink == menu[i] and state == ACCEPT) {
			state = CHECK;
			currOrder = i;
			return "You have ordered " + drink + ";";
		}
	}
	state = WAIT;
	return "Incorrect drink name;";
}

bool Automata::check() {
	if (prices[currOrder] <= cash and state == CHECK){
		state = COOK;
		return true;
	}
	else {
		state = WAIT;
		return false;
	}
}

string Automata::cook() {
	if (state != CHECK) {
		state = WAIT;
		return "Can`t cook a drink;";
	}
	else {
		if (check()) {
			state = COOK;
			return "Cooking...\n " + menu[currOrder] + " is done!;";
		}
		else {

			return "Not enough money;";
		}
	}
}

string Automata::cancel() {
	if (state == ACCEPT || state == CHECK) {
		state = WAIT;
		unsigned change = cash;
		cash = 0;
		return "You`ve canceled the operation;  Your change is: " + to_string(change) + ';';
	}
	else {
		return "Can`t cancel the operation;";
	}
		
}

string Automata::finish() {
	if (state == COOK) {
		state = WAIT;
		cash -= prices[currOrder];
		return "Bon appetit! Your change is: " + to_string(cash) + ';';
	}
	else {
		return "Can`t finish the operation;";
	}	
}

string Automata::printMenu() {
	string menuStr = "Menu: \n";
	for (size_t i = 0; i < 6; i++) {
		menuStr += "Drink: " + menu[i] + '|' + "Price: " + to_string(prices[i]) + '\n';
	}
	return menuStr;
}

string Automata::printState() {
	switch (state)
	{
	case(OFF):
		return "The state is: OFF";

	case(WAIT):
		return "The state is: WAIT";

	case(CHECK):
		return "The state is: CHECK";

	case(ACCEPT):
		return "The state is: ACCEPT";

	case(COOK):
		return "The state is: COOK";
	}
}