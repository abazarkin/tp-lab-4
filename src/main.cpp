#include "Automata.h"

int main(){
	Automata a = Automata();
	a.on();
	a.printMenu();
	a.coin(6);
	a.choice(COLA);
	a.returnMoney();
	getchar();
}