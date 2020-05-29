#include"automata.h"
#include<iostream>

using namespace std;

int main() {
	Automata automata;
	automata.on();
	automata.printMenu();
	automata.coin(19);
	automata.choice("Water");
	automata.coin(1);
	automata.choice("Water");
	automata.off();
	return 0;
}