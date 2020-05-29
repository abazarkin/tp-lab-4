#include"automata.h"
#include<iostream>

using namespace std;

Automata::Automata() {
	state = OFF;
	cash = 0;
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		std::cout << "Automata on" << endl;
	}
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
		std::cout << "Automata off" << endl;
	}
}

void Automata::coin(unsigned int money) {
	if (state == ACCEPT || state == WAIT) {
		state = ACCEPT;
		cash += money;
		std::cout << "Your deposit :" << money << endl;
	}
	else {
		std::cout << "Error" << endl;
	}
}

void Automata::printMenu() {
	std::cout << "Menu: " << endl;
	for (int i = 0; i < 6; i++) {
		std::cout << menu[i] << " Price: " << prices[i] << "\n";
	}
}

void Automata::printState() {
	switch (state)
	{
	case(OFF):
		std::cout << "State: OFF";

	case(WAIT):
		std::cout << "State: WAIT";

	case(ACCEPT):
		std::cout << "State: ACCEPT";

	case(CHECK):
		std::cout << "State: CHECK";

	case(COOK):
		std::cout << "State: COOK";
	}
}

string Automata::choice(string drink) {
	if (state == ACCEPT) {
		for (int i = 0; i < 6; i++) {
			if (drink == menu[i]) {
				state = CHECK;
				check(i);
			}
		}

	}
	else {
		std::cout << "Error" << endl;
	}
	return drink;
}

void Automata::check(const int number) {
	if (prices[number] <= cash) {
		std::cout << "Wait..." << endl;
		cash -= prices[number];
		cook();
	}
	else {
		std::cout << "Not enough cash" << endl;
		state = ACCEPT;
	}
}

void Automata::cancel() {
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		cash = 0;
		std::cout << "Take your cash" << endl;
	}
}

void Automata::cook() {
	if (state == CHECK) {
		state = COOK;
		std::cout << "Take your drink" << endl;
		finish();
	}
	else {
		cout << "Error" << endl;
	}
}

void Automata::finish() {
	if (state == COOK) {
		state = WAIT;
	}
}