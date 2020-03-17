#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <string>
#include <vector>

using namespace std;

class Automata {
private:
	enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};
	static const string STATES_STRINGS[];
	enum STATES currentState = OFF;
	unsigned mCash = 0;
	unsigned drinks = 0;
	unsigned drinkChosen = 0;
	int maxStringLen = 0;
	vector<string> mMenu;
	vector<unsigned> mPrices;
public:
	Automata(const vector<string>& menu, const vector<unsigned>& prices);
	Automata(const string menuFileName, const string pricesFileName);
	bool on();
	bool off();
	void printMenu();
	void printState();
	bool choise(unsigned drinkId);
	bool choise(const string name);
	bool coin(unsigned cash);
	bool check();
	bool cook();
	bool finish();
	bool cancel();
};

#endif // !AUTOMATA_H
