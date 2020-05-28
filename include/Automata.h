#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

struct Drink {
	std::string name;
	int price;
};

class Automata {
	enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK } state = OFF; // состояние автомата
	static std::string state_description[];
	std::string the_chosen_one;
	int cash = 0; // для хранения текущей суммы;
	std::vector<Drink> menu; // меню автомата
	bool check(std::string the_chosen_one); // проверка наличия необходимой суммы
	std::string finish(); // завершение обслуживания пользователя
public:
	Automata(std::vector<Drink> storage);
	void on(); // включение автомата
	void off();	// выключение автомата
	std::string coin(int cash); // занесение денег на счёт пользователем
	std::string printMenu();	// отображение меню с напитками и ценами для пользователя
	std::string printState(); // отображение текущего состояния для пользователя
	std::string choice(std::string the_chosen_one); // выбор напитка пользователем
	std::string cancel(); // отмена сеанса обслуживания пользователем
	std::string cook(); // имитация процесса приготовления напитка
};

#endif