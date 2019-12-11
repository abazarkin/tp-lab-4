#include "automata.h"

void Automata::printState()
{
	cout <<"cur state: " <<  state << endl;
}
void Automata::printMenu()
{
	for (int i = 0; i < dishes; i++)
	{
		cout << i << ") " << menu[i] << endl;
	}
}
void Automata::setMenu(string* strs, int *pr, int N)
{
	dishes = N;
	if (menu)
	{
		delete[] menu;
		delete[] prices;

	}
	menu = new string[N];
	prices = new int[N];
	for (int i = 0; i < N; i++)
	{
		menu[i] = strs[i];
		prices[i] = pr[i];
	}
}
void Automata::setMenu(int N)
{
	dishes = N;
	if (menu)
	{
		delete[] menu;
		delete[] prices;

	}
	menu = new string[N];
	prices = new int[N];
	for (int i = 0; i < N; i++)
	{
		string buf = "";
		cin >> buf;
		menu[i] = buf;
		cin >> prices[i];

	}
}
bool Automata::check()
{
	if (chosenNum == -1) return false;
	return cash == (prices[chosenNum]);
}
int Automata::cook()
{
	cout << "preparing..." << endl;
}
int Automata::finish()
{

}

void Automata::admin(int key)
{
	if (key != this->key) {
		cout << "ACCESS DENIED" << endl;
		return;
	}
	while (true)
	{
		int op;
		cin >> op;
		switch (op)
		{
		case 0: off();
			break;
		case 1: on();
			break;
		case 2: //set menu
			break;
		case 3: //set menu file
			break;
		case -1 : //exit
			return;
			break;
		default:
			break;
		}
	}
	
}

int Automata::on()
{
	if (state == "WAIT")
	{
		state = "ON";
		return 1;
	}
	else
	{
		return 0;
	}
}
int Automata::off()
{
	if (state == "WAIT")
	{
		state = "OFF";
		return 1;
	}
	else
	{
		return 0;
	}

}

int Automata::coin()
{
	cin >> cash;
}
int Automata::choise()
{
	printMenu();
	cin >> chosenNum;
	chosenNum--;
	if ((chosenNum >= dishes) || (chosenNum < 0))
	{
		cout << "INCORRECT" << endl;
		chosenNum = -1;
		return -1;
	}
	return 1;
}
int Automata::cansel()
{

}