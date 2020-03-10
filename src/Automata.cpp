#include "Automata.h" 
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

Automata::Automata(string file_menu, string file_prices) {
	string FileMenu = file_menu;
	string FilePrices = file_prices;
	cash = 0;
	state = OFF;
}

void Automata::makeMenu() {
	{

		ifstream file("menu.txt");
		if (file.is_open()) {
			string NameOfDrink;
			
			while (getline(file, NameOfDrink)) {
				menu.push_back(NameOfDrink);
			}
		}
		else {
			cout << "Not open!";
		}
		file.close();
	}
}

void Automata::makePrices() {
	ifstream file("prices.txt");
	if (file.is_open()) {
		int ValueOfPrice;
		while (file>> ValueOfPrice) {
			prices.push_back(ValueOfPrice);
		}
	}
	else {
		cout << "Not open!";
	}
	file.close();
}

void Automata::on() {
	if (state == OFF) {
		state = WAIT;
		cout << "Ready for new job!" << endl;
	}
	else { 
		cout << "I am broken"<<endl; 
	}
}

void Automata::off() {
	if (state == WAIT) {
		cout << "Time is over" << endl;
		state = OFF;
	}
}

int Automata::coin(int NewSum) {
	if (state == WAIT || state == ACCEPT) {
		cout << "Put your money" << endl;
		cash =cash+ NewSum;
		state = ACCEPT;
		cout << "In the bank is:" << cash << endl;
	}
	else {
		cout << "where's the money?" << endl;
	}
	return cash;
}

void Automata::printMenu() {
	for (int i = 0; i < menu.size(); i++) {
		cout << menu[i] << " " << prices[i] << endl;
	}
}

string Automata::printState() {
	switch (state) {
	case OFF:
		return "State is OFF";
		
	case WAIT:
		return "State is  WAIT";
		
	case ACCEPT:
		return "State is ACCEPT";
		
	case CHECK:
		return "State is CHECK";
	
	case COOK:
		return "State is COOk";
		
	}
}
int Automata::GetCash() {
	return this->cash;
}
string Automata::choice(int Choise) {
	if (state == ACCEPT) {
		for (int i = 0; i < menu.size(); i++) {
			if (Choise == i) {
				state = CHECK;
				check(i);
			}
		}
		return menu[Choise];
	}
	else { cout << "What do you mean?" << endl; }
}

void Automata::check(int VPrice) {
	if (state == CHECK) {
		if (prices[VPrice] <= cash) {
			cash = cash - prices[VPrice];
			cout << "Ready for cooking!" << endl;
			cook();
		}
		else { cout << "Add more money!" << endl;
		state = WAIT;
		coin(prices[VPrice] - cash);
		state = ACCEPT;
		check(VPrice);

		}
	}
	else { cout << "I was broken" << endl; }
}

void Automata::cook() {
	if (state == CHECK)
	{
		state = COOK;
		cout << "Wait..." << endl;
		finish();
	}
	else
	{
		cout << "Sorry, i was broken" << endl;
	}
}
void Automata::cancel() {
	if (state == ACCEPT || state == CHECK) {
		state = WAIT;
		off();
	}
}
void Automata::finish() {
	if (state == COOK)
	{
		state = WAIT;
		cout << "Enjoy" << endl;
		off();
	}
	else
	{
		cout << "Sorry, i was broken" << endl;
	}
}