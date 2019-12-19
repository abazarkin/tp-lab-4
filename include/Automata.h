#pragma once
#include <string>

enum states {OFF, WAIT, ACCEPT, CHECK, COOK };
using namespace std;

class Automata
{
	private:
		unsigned cash;
		states state;
		size_t currOrder;

		static string menu[6];
		static unsigned prices[6];

	public:

		Automata();

		string on();
		string off();
		string coin(const unsigned);
		string choiñe(const string);
		string printMenu();
		string printState();
		bool check();
		string cancel();
		string cook();
		string finish();


};
