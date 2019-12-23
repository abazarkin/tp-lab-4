#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include "gtest/gtest.h"

class CoffeeMachine {

private:
	enum STATES {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK,
		COMPLETE,
	};
	//errors, whose codes are their indices in the array
	//code of success is 100
	std::string errors[6] = { "The coffee machine is already on",
							"Can not turn off",
							"where's the money?",
							"Uncorrect number of drink",
							"Unable to complete operation",
							"Not enough money" };
	unsigned int cash;
	static std::string menu[5];
	static unsigned int prices[5];
	STATES current_state;
	int numberSelectedDrink;
	void printMenu();
	void changeState(STATES state);
public:
	//constructor
	CoffeeMachine();
	int on();
	int off();
	int coin(int money);
	int choice(int drink);
	int check();
	int cancel();
	int cook();
	int finish();
};
