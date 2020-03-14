#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum STATES {OFF,WAIT,ACCEPT,CHECK,COOK};


class Automata
{
private:
	int cash;
	vector<string> menu = {"Black_tea","Green_tea","Latte", "Cappuccino", "Espresso", "Hot_chocolate"};
	vector<int> prices = {10,10,25,30,20,35};
	STATES state;
public:
	Automata(); 
	void on();
	void off();
	void coin(int mon); //занесение денег на счёт пользователем;
	void printMenu(); 
	void printState();
	void cancel();// отмена сеанса обслуживания пользователем;
	void choice(int tmp_choice);
	bool check(int tmp_price); //проверка наличия необходимой суммы;
	void cook(string tmp_menu);
	void finish();//завершение обслуживания пользователя.

};
