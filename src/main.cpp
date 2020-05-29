#include "Automata.h"
#include <iostream>

using namespace std;

int main() {
	Automata box;
	cout<<box.printState()<<'\n';
	box.on();
	cout<<box.printState()<<'\n';
	box.printMenu(cout);
	cout<<box.coin(5)<<'\n';
	cout<<box.choice(2)<<'\n';
	cout<<box.cook()<<'\n';
	cout<<box.cook()<<'\n';
	cout<<box.coin(1)<<'\n';
	box.cancel();
	cout<<box.choice(3)<<'\n';
	box.off();
}