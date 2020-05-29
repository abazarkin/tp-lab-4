#include "Automata.h"
#include <iostream>
#include <fstream>
#include <iomanip>

const string Automata::STATES_STRINGS[] = { 
	"Turned off.", 
	"Waiting for your order.", 
	"Accepting money.", 
	"Ready to cook.", 
	"Cooking your drink." };

Automata::Automata(const vector<string>& menu, const vector<unsigned>& prices) {
	if (menu.size() < prices.size()) {
		drinks = menu.size();
	}
	else {
		drinks = prices.size();
	}
	for (auto i = 0; i < drinks; i++) {
		mMenu.push_back(menu[i]);
		if (mMenu[i].length() > maxStringLen) {
			maxStringLen = mMenu[i].length();
		}
		mPrices.push_back(prices[i]);
	}
}

Automata::Automata(const string menuFileName, const string pricesFileName) {
	ifstream fIn(menuFileName);
	string buffer;
	while (!fIn.eof()) {
		getline(fIn, buffer);
		mMenu.push_back(buffer);
		if (buffer.length() > maxStringLen) {
			maxStringLen = buffer.length();
		}
	}
	fIn.close();
	fIn.open(pricesFileName);
	while (!fIn.eof()) {
		getline(fIn, buffer);
		mPrices.push_back(stoi(buffer));
	}
	drinks = (mMenu.size() > mPrices.size()) ? mMenu.size() : mPrices.size();
	fIn.close();
}

bool Automata::on() {
	if (currentState == OFF) {
		cout << "Turning on." << endl;
		currentState = WAIT;
		return true;
	}
	return false;
}

bool Automata::off() {
	if (currentState == WAIT) {
		cout << "Turning off." << endl;
		currentState = OFF;
		return true;
	}
	return false;
}

void Automata::printMenu() {
	cout << "Menu:" << endl;
	for (auto i = 0; i < drinks; i++) {
		cout << setw(maxStringLen + 2) << left << mMenu[i] + ": " << mPrices[i] << endl;
	}
}

void Automata::printState() {
	cout << "Current state: " << STATES_STRINGS[currentState] << endl;
}

bool Automata::choise(unsigned drinkId) {
	if ((currentState == WAIT || currentState == ACCEPT) && drinkId < drinks) {
		drinkChosen = drinkId;
		cout << "You chose " << mMenu[drinkChosen] << "." << endl;
		currentState = CHECK;
		return true;
	}
	return false;
}

bool Automata::choise(const string name) {
	if (currentState == WAIT || currentState == ACCEPT) {
		for (auto i = 0; i < drinks; i++) {
			if (mMenu[i].compare(name) == 0) {
				return choise(i);
			}
		}
	}
	return false;
}

bool Automata::check() {
	if (currentState == CHECK) {
		if (mCash >= mPrices[drinkChosen]) {
			cout << "You put enough coins." << endl;
			return true;
		}
		cout << "Not enough money." << endl;
		return false;
	}
	return false;
}

bool Automata::cancel() {
	if (currentState == ACCEPT || currentState == CHECK) {
		if (mCash > 0) {
			cout << "Returning " << mCash << " coins." << endl;
			mCash = 0;
		}
		currentState = WAIT;
		return true;
	}
	return false;
}

bool Automata::coin(unsigned money) {
	if (currentState == WAIT || currentState == ACCEPT) {
		mCash += money;
		cout << "You put " << money << " coins." << endl;
		currentState = ACCEPT;
		return true;
	}
	return false;
}

bool Automata::cook() {
	if (check()) {
		if (mCash > mPrices[drinkChosen]) {
			cout << "Your change of " << mCash - mPrices[drinkChosen] << " coins." << endl;
		}
		mCash = 0;
		cout << "Cooking " << mMenu[drinkChosen] << "." << endl;
		currentState = COOK;
		return true;
	}
	return false;
}

bool Automata::finish() {
	if (currentState == COOK) {
		cout << "Here is your " << mMenu[drinkChosen] << ". Enjoy!" << endl;
		currentState = WAIT;
		return true;
	}
	return false;
}