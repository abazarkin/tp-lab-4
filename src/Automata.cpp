#include "Automata.h"
#include <iostream>
using namespace std;


Automata::Automata(){
	Money = 0;
	CurrentState = OFF;
}

void Automata::on(){
	if (CurrentState == OFF){
		CurrentState = WAIT;
		cout << "Waiting for orders..." << endl;
	}
}

void Automata::off(){
	if (CurrentState == WAIT){
		if (Money != 0) {
			CurrentState = ACCEPT;
			cancel();
		}
		CurrentState = OFF;
		cout << "Thanks for orders" << endl;
	}
}

int Automata::coin(unsigned int sum){
	if (CurrentState == WAIT || CurrentState == ACCEPT){
		CurrentState = ACCEPT;
		Money = Money + sum;
		cout << "Current balance: " << Money << endl;
	}
	else{
		cout << "Error, unable to accept the money" << endl;
	}
	return Money;
}

void Automata::printMenu(){
	cout << "Menu:" << endl;
	for (int i = 0; i < 9; i++){
		cout << i + 1 << ")" << Menu[i] << " : " << Prices[i] << " coins"<< endl;
	}
}

void Automata::printState() {
	switch (CurrentState){
	case OFF:
		cout << "State: OFF" << endl;
		break;
	case WAIT:
		cout << "State: WAIT" << endl;
		break;
	case ACCEPT:
		cout << "State: ACCEPT" << endl;
		break;
	case CHECK:
		cout << "State: CHECK" << endl;
		break;
	case COOK:
		cout << "State: COOK" << endl;
		break;
	}
}

string Automata::choice(string c){
	if (CurrentState == ACCEPT){
		for (int i = 0; i < 9; i++){
			if (c == Menu[i]){
				CurrentState = CHECK;
				cout << "Your choice is " << Menu[i] << " it cost " << Prices[i] << " coins" << endl;
				check(i);
			}
		}
	}
	else{
		cout << "Error, unable to choose the drink" << endl;
	}
	return c;
}


void Automata::check(const int num) {
	if (CurrentState == CHECK){
		if (Prices[num] <= Money){
			Money = Money - Prices[num];
			cout << "Start cooking..." << endl;
			cook();
		}
		else{
			cout << "Not enough money, please deposit more or choose another drink" << endl;
		}
	}
	else{
		cout << "Error, unable to check" << endl;
	}
}


void Automata::cancel() {
	if (CurrentState == CHECK || CurrentState == ACCEPT){
		CurrentState = WAIT;
		cout << "Cancelling, please, take your money: " << Money << " coins"<< endl;
		Money = 0;
	}
	else{
		cout << "Error, unable to cancel now" << endl;
	}
}


void Automata::cook() {
	if (CurrentState == CHECK){
		CurrentState = COOK;
		cout << "Cooking in process..." << endl;
		finish();
	}
	else{
		cout << "Error, unable to cook" << endl;
	}
}

void Automata::finish() {
	if (CurrentState == COOK){
		CurrentState = WAIT;
		cout << "Cooking is finished, enjoy your drink!" << endl;
		off();
	}
	else{
		cout << "Error, unable to finish" << endl;
	}
}