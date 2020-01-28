#include "Automata.h"

string Automata::menu[] = { "Latte", "Cappuccino", "Macchiato", "Mochaccino", "Espresso", "Americano", "Russian raf", "Classic tea", "Glasse" };
int Automata::prices[] = { 30, 35, 35, 40, 50, 50, 55, 25, 40 };

Automata::Automata() : cash(0), state(OFF) {}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		cout << "Automata is on" << endl;
	}
	else
		cout << "Automata has been already on" << endl;
}

void Automata::off() {
	if (state == WAIT) {
		state = OFF;
		cash = 0;
		cout << "Automata is off" << endl;
	}
	else
		cout << "Automata has been already off" << endl;
}

int Automata::coin(int money) {
	if (state != WAIT && state != ACCEPT) {
		cout << "In order to add money, keep Automata in wait or accept state" << endl;
		return 0;
	}
	if (state == WAIT) state = ACCEPT;
	cout << "Insert your coin" << endl;
	if (money <= 0) {
		cout << "Money cannot have negative value!" << endl;
		return 0;
	}
	cash += money;
	cout << "You add " << money << " rub" << endl;
	return cash;
}

bool Automata::choice(int drink) {
	if (state != ACCEPT) {
		cout << "In order to make a choice, insert money into Automata" << endl;
		return false;
	}
	state = CHECK;
	if ((drink >= 0) && (drink < N)) {
		if (check(drink)) {
			cash -= prices[drink];
			cook();
			finish();
			return true;
		}
		else {
			cout << "You haven't enough money" << endl;
			cancel();
			return false;
		}
	}
	else cout << "The number of item is invalid. Choose another item" << endl;
	return false;
}

bool Automata::check(int drink) {
	state = CHECK;
	cout << "Your balance is " << cash << " rub, and the drink price is " << prices[drink] << " rub" << endl;
	return cash >= prices[drink];
}

void Automata::cook() {
	state = COOK;
	cout << "Please, wait for one minute" << endl;
	cout << "Cooking..." << endl;
	cout << "Cooking..." << endl;
	cout << "Cooking..." << endl;
}

void Automata::cancel() {
	state = WAIT;
	cout << "The operation is cancelled" << endl;
}

void Automata::finish() {
	state = WAIT;
	cout << "Enjoy your drink!" << endl;
}

void Automata::getMenu() {
	cout << "~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < N; i++)
		cout << menu[i] << " " << prices[i] << " rub" << endl;
	cout << "~~~~~~~~~~~~~~~~" << endl;
}

const string Automata::getState() {
	switch (state) {
	case OFF: return "OFF";
	case WAIT:return "WAIT";
	case ACCEPT: return "ACCEPT";
	case CHECK: return "CHECK";
	case COOK:	return "COOK";
	}
}