#include "Automata.h"

Automata::Automata(){
	cash = 0;
	state = OFF;
	menu[0] = "tea";
	menu[1] = "coffe";
	menu[2] = "cola";
	prices[0] = 2;
	prices[1] = 1;
	prices[2] = 5;
}

void Automata::on(){
	if (state == OFF)
		state = WAIT;
	printState();
}

void Automata::off(){
	state = OFF;
	printState();
}

void Automata::coin(int income){
	if (state == OFF)
		cout << "turn on the automata" << endl;
	else{
		state = ACCEPT;
		printState();
		cash += income;
		cout << "balance is" << cash << endl;
	}
}

void Automata::printMenu(){
	if (state == OFF)
		cout << "turn on the automata" << endl;
	else{
		cout << "drinks: ";
		for (int i = 0; i < sizeof(menu)/sizeof(menu[0]); i++)
			cout << menu[i] << ", ";
		cout << endl;
	}
}

void Automata::printState(){
	if (state == OFF)
		cout << "off" << endl;
	if (state == WAIT)
		cout << "wait" << endl;
	if (state == ACCEPT)
		cout << "accept" << endl;
	if (state == CHECK)
		cout << "check" << endl;
	if (state == COOK)
		cout << "cook" << endl;
}

void Automata::choice(DRINKS drink){
	if (state == OFF)
		cout << "turn on the automata" << endl;
	else{
		if (drink == TEA || drink == COFFE || drink == COLA){
			if (check(drink))
				cook(drink);
			else
				cout << "need more money" << endl;
		}
		else{
			cout << "choose drink from the list" << endl;
				printMenu();
		}
	}
}

bool Automata::check(DRINKS drink){
	state = CHECK;
	printState();
	if (cash >= prices[drink])
		return true;
	else
		return false;
}

void Automata::cancel(){
	if (state == WAIT || state == OFF)
		cout << "nothing to cancel" << endl;
	else{
		state = WAIT;
		printState();
		cout << "cooking cancelled" << endl;
	}
}

void Automata::cook(DRINKS drink){
	state = COOK;
	printState();
	cash -= prices[drink];
	finish();
}

void Automata::finish(){
	cout << "drink is ready" << endl;
	state = WAIT;
	printState();
}

void Automata::returnMoney(){
	if (cash != 0){
		cout << "take your change: " << cash << " coin(s)" << endl;
		cash = 0;
	}
	else
		cout << "you have no change" << endl;
}

int Automata::getCash(){
	return cash;
}