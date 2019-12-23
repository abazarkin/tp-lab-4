#include "CoffeeMachine.h"

std::string menu[5] = { "Cappuccino", "Latte", "Espresso", "Americano", "Tea" };
unsigned int prices[5] = { 30,35,35,40,25 };

//constructor
CoffeeMachine::CoffeeMachine() {
	cash = 0;
	current_state = OFF;
	numberSelectedDrink = -1;
}

int CoffeeMachine::on() {
	if (current_state == OFF) {
		changeState(WAIT);
		printMenu();
		//success
		return 100;
	}
	else {
		//coffe machine is alredy on
		std::cout << errors[0] << std::endl;
		//code of error			
		return 0;
	}
}
	
int CoffeeMachine::off() {
	if (current_state == WAIT) {
		changeState(OFF);
		return 100;
	}
	else {
		//can not to turn off
		std::cout << errors[1] << std::endl;
		return 1;
	}
}
	
int CoffeeMachine::coin(int money) {
	if (current_state == WAIT || current_state == ACCEPT) {
		if (current_state == WAIT) {
			changeState(ACCEPT);
		}
		if (money > 0) {
			cash += money;
		}
		return 100;
	}
	else {
		//money was not received
		std::cout << errors[2] << std::endl;
		return 2;
	}
}
	
int CoffeeMachine::choice(int drink) {
	if (current_state == ACCEPT) {
		if (drink >= 0 && drink <= 4) {
			numberSelectedDrink = drink;
			changeState(CHECK);
		}
		else {
			//Uncorrect number of drink
			std::cout << errors[3] << std::endl;
			return 3;
		}
		return 100;
	}
	else {
		//It is impossible to go to this state from the previous
		std::cout << errors[4] << std::endl;
		return 4;
	}
}
	
int CoffeeMachine::check() {
	if (current_state == CHECK) {
		if (cash > prices[numberSelectedDrink]) {
			std::cout << "Wait please" << std::endl;
			cash -= prices[numberSelectedDrink];
			return 100;
		}
		else {
			std::cout << errors[5] << std::endl;
			//not enought cash
			return 5;
		}
	}
	else {
		std::cout << errors[4] << std::endl;
		//It is impossible to go to this state from the previous
		return 4;
	}
}
	
int CoffeeMachine::cancel() {
	if (current_state == CHECK || current_state == ACCEPT) {
		changeState(WAIT);
		return 100;
	}
	else {
		//It is impossible to go to this state from the previous
		std::cout << errors[4] << std::endl;
		return 4;
	}
}
	
int CoffeeMachine::cook() {
	if (current_state == CHECK) {
		changeState(COOK);
		for (int i = 0; i < 5; i++) {
			std::cout << i * 20 << "% has cooked\r";
			Sleep(1800);
		}
		std::cout << "100% has cooked" << std::endl;
		return 100;
	}
	else {
		//It is impossible to go to this state from the previous
		std::cout << errors[4] << std::endl;
		return 4;
	}
}
	
int CoffeeMachine::finish() {
	if (current_state == COOK) {
		changeState(WAIT);
		if (cash > 0) {
			std::cout << "Take your change " << cash << std::endl;
			cash = 0;
			numberSelectedDrink = -1;
		}
		return 100;
	}
	else {
		//It is impossible to go to this state from the previous
		std::cout << errors[4] << std::endl;
		return 4;
	}
}
void CoffeeMachine::printMenu() {
	unsigned int size = sizeof(menu) / sizeof(std::string);
	for (int i = 0; i < size; i++) {
		std::cout << i << " " << menu[i] << "  " << prices[i] << std::endl;
	}
}
void CoffeeMachine::changeState(STATES state) {
	current_state = state;
	switch (current_state) {
	case WAIT:
		std::cout << "WAIT" << std::endl;
		break;
	case ACCEPT:
		std::cout << "ACCEPT" << std::endl;
		break;
	case CHECK:
		std::cout << "CHECK" << std::endl;
		break;
	case COOK:
		std::cout << "COOK" << std::endl << "Your drink is cooking" << std::endl;
		break;
	case COMPLETE:
		std::cout << "COMPLETE" << "Take your drink" << std::endl;
		break;
	}
}

