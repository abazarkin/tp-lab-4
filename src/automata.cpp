#include "C:\Users\nuald\source\repos\tp-lab-4\include\automata.h"

Automata::Automata()
{
	chosenNum = -1;
	key = 1234;
	state = OFF;
	m.n = 0;
	m.dishes = NULL;
	m.prices = NULL;
}

states Automata::getState() const
{
	return state;
}

menu Automata::getMenu() const
{
	return m;
}

int Automata::getCash() const
{
	return cash;
}

void Automata::setMenu(string* strs, int *pr, int N)
{
	m.n = N;
	if (m.dishes)
	{
		delete[] m.dishes;
		delete[] m.prices;

	}
	m.dishes = new string[N];
	m.prices = new int[N];
	for (int i = 0; i < N; i++)
	{
		m.dishes[i] = strs[i];
		m.prices[i] = pr[i];
	}
}
void Automata::setMenu(int N)
{
	m.n = N;
	if (m.dishes)
	{
		delete[] m.dishes;
		delete[] m.prices;

	}
	m.dishes = new string[N];
	m.prices = new int[N];
	for (int i = 0; i < N; i++)
	{
		string buf = "";
		cin >> buf;
		m.dishes[i] = buf;
		cin >> m.prices[i];

	}
}
bool Automata::check()
{
	if (chosenNum == -1) return false;
	return cash == (m.prices[chosenNum]);
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

returns Automata::on()
{
	if (state == OFF)
	{
		if (m.dishes)
		{
			state = WAIT;
		}
		else
		{
			state = ERROR;
		}
		return CORRECT;
	}
	else
	{
		return MISTAKE;
	}
}
returns Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
		return CORRECT;
	}
	else
	{
		return MISTAKE;
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