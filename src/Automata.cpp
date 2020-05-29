#include "Automata.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Automata::Automata() 
{
	this->cash = 0;
	this->state = OFF;
}

void Automata::on()
{
	cout << "HELLO" << endl;
	this->state = WAIT;
	printState();
	cout << "add your cash" << endl;
}

void Automata::off() 
{
	this->state = OFF;
	printState();
}

void Automata::coin(int mon) 
{
	this->state = ACCEPT;
	printState();
    this->cash += mon;
}

void Automata::printMenu() 
{
	cout << "----------MENU----------" << endl;

	for (int i = 0; i < this->prices.size(); i++) 
	{
		cout<<i<<"   " <<this->menu[i]<<"   "<<this->prices[i]<<endl;
	}

	cout << "------------------------" << endl;
}

void Automata::printState()
{
	cout <<"AUTOMATE - ";
	if(this->state==0)
	cout<<"OFF"<<endl;
	if (this->state == 1)
		cout << "WAIT" << endl;
	if (this->state == 2)
		cout << "ACCEPT" << endl;
	if (this->state == 3)
		cout << "CHECK" << endl;
	if (this->state == 4)
		cout << "COOK" << endl;
}

void Automata::cancel() 
{
	this->state = WAIT;
	printState();
	cout << "return your cash" << endl;
	this->cash = 0;
}

void Automata::finish()
{
	cout << "return change" << endl;
	cout << "thanks for visiting" << endl;
	off();
	this->cash = 0;
}

void Automata::cook(string tmp_menu) 
{
	this->state = COOK;
	printState();
	cout << "cooking " << tmp_menu <<endl;
	finish();
}

bool Automata::check(int tmp_price)
{
	return tmp_price <= this->cash;
}

void Automata::choice(int tmp_choice)
{
	this->state = CHECK;
	printState();
	if (check(this->prices[tmp_choice]) == 0)
	{
		cout << "add cash"<<endl;
	}
	else
	{
		cook(this->menu[tmp_choice]);
	}

}

