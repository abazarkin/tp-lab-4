#include "Automata.h"
#include <stdio.h>
#include <string>
#include <iostream>
//#include "windows.h"


using namespace std;

// 0 - off | 1 - wait | 2 - accept | 3 - check | 4 - cook //
Automata::Automata() {
	cash = 0;
	state = 1;
}//конструктор

void Automata::on() {
	if (state == 1) {
		std::cout << "\n" << "Machine is already ON";
		return;
	}
	state = 1;
	printState();
} //- включение автомата;

void Automata::off() {
	std::cout << "\n" << "Have a nice day!";
	state = 0;
	printState();
	//exit(1);
}// - выключение автомата;

int Automata::coin(int _cash) {
	state = 2;
	if (_cash < 0) {
		std::cout << "\n" << "Incorrect number!";
		return -1;
	}
	printState();
	if (_cash == 0) {
		cancel();
	}
	this->cash += _cash;
	return this->cash;
} //- занесение денег на счёт пользователем;

void Automata::printMenu() {
	if (state != 0) {
		std::cout << "Drink" << "|   |" << "Price";
		for (int i = 0; i < 6; i++) {
			std::cout << "\n" << i + 1 << ".|" << this->menu[i] << " |" << " - " << "| " << this->prices[i] << " |";
		}
	}
} //- отображение меню с напитками и ценами для пользователя;

int Automata::printState() {
	if (state == 0) {
		std::cout << "\n" << "OFF" << "\n";
	}

	if (state == 1) {
		std::cout << "\n" << "WAIT" << "\n";
	}

	if (state == 2) {
		std::cout << "\n" << "ACCEPT" << "\n";
	}

	if (state == 3) {
		std::cout << "\n" << "CHECK" << "\n";
	}

	if (state == 4) {
		std::cout << "\n" << "COOK" << "\n";
	}
	return(state);
}// - отображение текущего состояния для пользователя;	

void Automata::choice() {
	int choice;
	int _cash;
	if (state == 0) {
		std::cout << "\n" << "The Machine is OFF";
		return;
	}
	state = 1;
	printState();
	printMenu();
	std::cout << "\n" << "Please, choose the number of drink you want ";
	std::cin >> choice;
	choice -= 1;
	if ((choice > 5) or (choice < 0)) {
		std::cout << "\n" << "You have inserted incorrect number";
		return;
	}
	std::cout << "\n" << "Now insert cash or cancel by pressing 0: ";
	std::cin >> _cash;
	coin(_cash);
	while (!(check(choice))) {
		std::cout << "\n" << "Please, Add money or cancel by pressing 0: ";
		std::cin >> _cash;
		coin(_cash);
	}
	//if (check(choice)) {
	cook();
	state = 1;
	finish();
	//}
} //- выбор напитка пользователем;

bool Automata::check(int _i) {
	state = 3;
	printState();
	if (prices[_i] > cash) {
		std::cout << "\n" << "Not enough money";
		return false;
	}
	else {
		cash -= prices[_i];
		return true;
	}
}// - проверка наличия необходимой суммы;

int Automata::cancel() {
	std::cout << "\n" << "Take your money - " << cash;
	return cash;
	//off();
}// - отмена сеанса обслуживания пользователем;

void Automata::cook() {
	state = 4;
	printState();
	std::cout << "\n" << "Your drink is preparing now";
	std::cout << "\n" << ".";
	//Sleep(1000);
	std::cout << "\n" << "..";
//	Sleep(2000);
	std::cout << "\n" << "...";
	//Sleep(3000);
//	Beep(523, 350);
	std::cout << "\n" << "Your drink is ready";
}// - имитация процесса приготовления напитка;

void Automata::finish() {
	std::cout << "\n" << "Take your money - " << cash;
	off();
}// - завершение обслуживания пользователя.