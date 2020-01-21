#include "automata.h"
#include "string_def.h" //library with defined strings
#include <string>

using namespace std;

Automata::Automata(){
    cash = 0;
    state = OFF;
	cached_state = WAIT;
	cached_cash = 0;
	menu_names = _menu_names_;
	menu_prices = _menu_prices_;
}

void Automata::console() {
	if (state == OFF) return;
	string command = "";

	while (command != "off") {
		command = "";
		cout << ">>>";
		cin >> command;
		if (command == "on") {
			on();
		}
		else if (command == "off") {
			off();
		}
		else if (command == "coin") {
			coin();
		}
		else if (command == "menu") {
			menu();
		}
		else if (command == "return_money") {
			return_money();
		}
		else if (command == "cook") {
			cook();
		}
		else if (command == "choice") {
			choice();
		}
	}
}

void Automata::on() {
	if (state != OFF) return;
	state = cached_state;
	cash = cached_cash;
	console();
}

void Automata::off(){
	cached_state = state;
	cached_cash = cash;
	cout << _off_ << endl;
    state = OFF;
}

void Automata::coin(){
	cout << _add_coin_message_;
	int money;
	cin >> money;
	if (state != OFF && state != COOK) {
		cash += money;
	}
}

void Automata::menu() {
	int count = 0;
	for (int i = 1; i <= menu_names.size(); i++) {
		cout << i << ": " << menu_names[i-1] << " ::: " << menu_prices[i-1] << " rub" << endl;
	}
}

void Automata::cancel() {
    if (state == OFF) return; 
	if (state == ACCEPT) {
		cout << _cancel_ << cash << endl;
		number_choice = 0;
		state = WAIT;
	}
}

void Automata::return_money() {
	if (state == OFF) return;
	if (state == WAIT) {
		cout << _return_money_ << cash << endl;
		cash = 0;
	}
	if (state == ACCEPT) {
		state = WAIT;
		number_choice = 0;
	}
}

void Automata::choice() {
	if (state == OFF) {
		return;
	}
	menu();
	cout << _choice_;
	int choice_tmp;
	cin >> choice_tmp;
	if (choice_tmp > 0 && choice_tmp <= menu_names.size()) {
		if (menu_prices[choice_tmp-1] > cash) {
			cout << _not_enough_money_ << cash - menu_prices[choice_tmp-1] << endl;
			state = WAIT;
			return;
		}
		number_choice = choice_tmp;
		state = ACCEPT;
		return;
	}
	if (choice_tmp == 0) {
		return;
	}
	cout << _error_choice_ << endl;
	state = WAIT;
}

void Automata::cook(){
	if (state == WAIT) {
		choice();
	}
	if (state == ACCEPT) {
		state = COOK;
		cout << _cook_ << menu_names[number_choice-1] << endl;
		cout << _cook_done_ << endl;
	}
	state = WAIT;
}
