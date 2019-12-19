#include "Automata.h"
#include <iostream>

int main() {
	Automata coffeeMachine{};

	cout << coffeeMachine.on() << endl;
	cout << coffeeMachine.printState() << endl;
	cout << coffeeMachine.printMenu() << endl;
	cout << coffeeMachine.coin(100) << endl;
	cout << coffeeMachine.coin(100) << endl;
	cout << coffeeMachine.printState() << endl;
	cout << coffeeMachine.choiñe("Water")<< endl;
	cout << coffeeMachine.cancel() << endl;
	cout << coffeeMachine.printState() << endl;
	cout << coffeeMachine.cook() << endl;
	cout << coffeeMachine.printState() << endl;
	cout << coffeeMachine.finish() << endl;
	cout << coffeeMachine.printState() << endl;
	cout << coffeeMachine.off() << endl;
	cout << coffeeMachine.printState() << endl;


}