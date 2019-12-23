#include"CoffeeMachine.h"

int main() {
	CoffeeMachine Igor = CoffeeMachine();
	Igor.on();
	std::cout << "Give me your money" << std::endl;
	int money;
	std::cin >> money;
	Igor.coin(money);
	int number;
	std::cout << "Choose the drink" << std::endl;
	std::cin >> number;
	if (Igor.choice(number) != 100) {
		Igor.cancel();
	}
	else if(Igor.check() == 100){
		Igor.cook();
		Igor.finish();
	}
	else {
		Igor.cancel();
	}
	Igor.off();
}