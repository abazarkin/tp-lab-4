#include "Automata.h"


Automata::Automata() {
	currentState = OFF;
}

string Automata::on() {
	if (currentState == OFF) {
		currentState = WAIT;
		cash = 0;
		return "Automata is ready to work!";
	}
	else
	{
		return "Automata is busy";
	}


}

string Automata::off() {
	if (currentState == WAIT) {
		currentState = OFF;
		cash = 0;
		return "Goodbye, friends zzz";
	}
	else
	{
		return "I'm busy, can't sleep";
	}
}

string Automata::coin(const unsigned cash) {
	if (currentState == WAIT or currentState == ACCEPT) {
		currentState = ACCEPT;
		this->cash += cash;
		return "Deposit " + to_string(cash) + ";\nBalance: " + to_string(this->cash) + ';';
	}
	else
	{
		return "I'm still busy";
	}

}

string Automata::choice(const string drink) {
	for (size_t i = 0; i < 6; i++) {
		if (drink == menu[i] and currentState == ACCEPT) {
			currentState = CHECK;
			currentOrder = i;
			return "You've ordered " + drink + ", nice taste :))";
		}
	}
	currentState = WAIT;
	return "I can't make such drink, choose the one i can!";
}

bool Automata::check() {
	if (prices[currentOrder] <= cash and currentState == CHECK) {
		currentState = COOK;
		return true;
	}
	else {
		currentState = WAIT;
		return false;
	}
}

string Automata::cook() {
	if (currentState != CHECK) {
		currentState = WAIT;
		return "Can`t cook a drink;((";
	}
	else {
		if (check()) {
			currentState = COOK;
			return "Cooking...\n " + menu[currentOrder] + " is done, here you go!";
		}
		else {

			return "Not enough money!";
		}
	}
}

string Automata::cancel() {
	if (currentState == ACCEPT || currentState == CHECK) {
		currentState = WAIT;
		unsigned change = cash;
		cash = 0;
		return "You`ve canceled the operation:(((  Your change is: " + to_string(change) + ';';
	}
	else {
		return "Can`t cancel the operation;";
	}

}

string Automata::finish() {
	if (currentState == COOK) {
		currentState = WAIT;
		cash -= prices[currentOrder];
		return "Time to take your drink! Your change is: " + to_string(cash) + ';';
	}
	else {
		return "Can`t finish :0";
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
	switch (currentState)
	{
	case(OFF):
		return "current state: OFF";

	case(WAIT):
		return "current state: WAIT";

	case(CHECK):
		return "current state: CHECK";

	case(ACCEPT):
		return "current state: ACCEPT";

	case(COOK):
		return "current state: COOK";
	}
}