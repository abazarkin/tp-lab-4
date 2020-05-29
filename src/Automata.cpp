#include <iostream>
#include <time.h>
#include "Automata.h"

using namespace std;

void pause(int seconds) 
{
	clock_t time_end;
	time_end = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < time_end);
}

Automata::Automata() {
	cash = 0;
	state = OFF;
}

void Automata::on() {
	if (state == OFF){
		state = WAIT;
		cout << "The automata has been turned ON" << endl;
	}
	else {
		cout << "The automata is already turned on!" << endl;
	}
}

void Automata::off() {
	if (state == OFF) {
		cout << "The automata is already turned off!" << endl;
	}
	else {
		state = OFF;
		cout << "The automata has been turned OFF" << endl;
	}
}

unsigned int Automata::coin(unsigned int money) {
	if (state == WAIT || state == ACCEPT) {
		state = ACCEPT;
		cash += money;
		printBalance();
	}
	return cash;
}

void Automata::printMenu() {
	cout << "Choose a drink:" << endl;
	for (int i = 0; i < (sizeof(menu) / sizeof(menu[0])); i++) {
		cout << i << " -- " << menu[i] << " -- " << prices[i] << endl;
	}
}

void Automata::printState() {
	cout << "List of avaliable drinks: " << endl;
	cout << state_text[state] << endl;
}

std::string Automata::getState() {
	return state_text[state];
}

void Automata::printBalance() {
	cout << "The current balance is: " << cash << endl;
}

unsigned int Automata::getBalance() {
	return cash;
}

void Automata::choice(unsigned int drink_num){
	if ((state == ACCEPT) || (state == WAIT)){
		if (drink_num < sizeof(menu) / sizeof(menu[0])) {
			cout << "You have chosen " << menu[drink_num] << endl;
			state = CHECK;
			check(drink_num);
		}
		else {
			cout << "No such drink!" << endl;
		}
	}
}

void Automata::check(unsigned int drink_num){
	if (prices[drink_num] <= cash) {
		cash -= prices[drink_num];
		cook();
	}
	else {
		cout << "Not enough money" << endl;
		cancel();
	}
}

void Automata::cancel() {
	state = WAIT;
}

void Automata::cook() {
	state = COOK;
	cout << "The drink is beeing cooked..." << endl;
	pause(1);
	cout << "...dropping a cup..." << endl;
	pause(1);
	cout << "...pouring your drink..." << endl;
	pause(1);
	finish();
}

void Automata::finish() {
	state = WAIT;
	cout << "Your drink is ready!" << endl;
	cout << endl;
}