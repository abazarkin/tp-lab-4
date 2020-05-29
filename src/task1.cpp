
#include "task1.h"
#include <iostream>

using namespace std;


Automata::Automata() {
	cash = 0;
	state = OFF;
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		std::cout << "Automata ON" << "\n";
	}
}

void Automata::off(){
	if (state == WAIT) {
		state = OFF;
		std::cout << "Automata OFF" << "\n";
	}
}

int Automata::coin(unsigned int money) {
	if (state == ACCEPT || state == WAIT) {
		state = ACCEPT;
		cash += money;
		std::cout << "Your deposit" << money<<"\n";
	}
	else {
		std::cout << "You can't add money" << "\n";
	}
	return cash;
}

void Automata::printMenu() {

	std::cout << "Menu: " << "\n";
	for (size_t i = 0; i < 6; i++) {
		std::cout<<"Drink: " <<menu[i]<<"   Price: "<<prices[i]<<"\n";
	}
}

void Automata::check(const int number) {
	if (state == CHECK) {
		if (prices[number] >= cash) {
			std::cout << "Your drink is preparing" << "\n";
			cash -= prices[number];
			cook();
		}
		else {
			std::cout << "Not enough money" << "\n";
		}
	}
	else {
		std::cout << "No purchase possible" << "\n";
	}
}



void Automata::printState() {
	if (state == OFF) {
		std::cout << "State: " << "OFF" << "\n";
	}

	if (state == WAIT) {
		std::cout << "State: " << "WAIT" << "\n";
	}

	if (state == ACCEPT) {
		std::cout << "State: " << "ACCEPT" << "\n";
	}

	if (state == CHECK) {
		std::cout << "State: " << "CHECK" << "\n";
	}

	if (state == COOK) {
		std::cout << "State: " << "COOK" << "\n";
	}
}

string Automata::choice(string number) {
	if (state == ACCEPT) {
		for (int i = 0; i < 6; i++) {
			if (number==menu[i])
			state = CHECK;
			check(i);
		}
		
	}
	else {
		std::cout << "You intered the wrong number" << "\n";
	}
	return number;
}


void Automata::cancel() {
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		cash = 0;
		std::cout << "Take money-" << cash << "\n";
	}
}

void Automata::cook(){
	if (state == CHECK){
		state = COOK;
		std::cout << "Your drink is being prepared" << "\n";
		finish();
	}
	else {
		cout << "You can't make a drink" << "\n";
	}
}

void Automata::finish() {
	if (state == COOK) {
		state = WAIT;
		cout << "You can take your drink" << "\n";
		off();
	}
}