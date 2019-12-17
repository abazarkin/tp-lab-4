#include <iostream>
#include "Automata.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	std::vector<Drink> v(5);
	v[0].name = "coffee";
	v[1].name = "tea";
	v[2].name = "water";
	v[3].name = "milk";
	v[4].name = "goo";
	v[0].price = 5;
	v[1].price = 5;
	v[2].price = 5;
	v[3].price = 5;
	v[4].price = 5;

	Automata box(v);
	box.on();
	box.coin(3);
	box.printMenu();
	box.printState();
	box.choice("milk");
	box.printState();
	box.cook();
	box.printState();
	box.cancel();
	box.printState();
	box.coin(10);
	box.printState();
	box.choice("tea");
	box.printState();
	std::string log = box.cook();
	cout << log;
	box.printState();
	box.off();
	box.printState();
}