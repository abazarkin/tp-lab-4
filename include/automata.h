#ifndef __AUTOMATA_H_
#define __AUTOMATA_H_

#include <string>
#include <vector>

class Automata
{
public:
	Automata(std::vector<std::string> menu, std::vector<int> prises);
	~Automata() { state = State::OFF; cash = 0; };

	void on()  { state == State::OFF  ? state = State::WAIT : state = state; };
	void off() { state == State::WAIT ? state = State::OFF  : state = state; };
	void coin(int);
	void choise(int);
	void cancel();
	bool check();
	void cook();
	std::string finish();

	std::string getState();

	std::vector<std::string> getMenu();


private:
	enum class State
	{
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK,
		NODRINKS
	};

	State state;
	unsigned cash;
	std::vector<std::string> menu;
	std::vector<int> prises;
	unsigned choosen_drink;
};

#endif // __AUTOMATA_H_