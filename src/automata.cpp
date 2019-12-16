#include "automata.h"

Automata::Automata()
{
	chosenNum = -1;
	cash = 0;
	key = 1234;
	state = OFF;
	m.n = 0;
	m.dishes = NULL;
	m.prices = NULL;
	ifstream fin;
	fin.open("menu.txt");	
	//setMenu(fin);
	fin >> m.n;
	m.dishes = new string[m.n];
	m.prices = new int[m.n];
	for (int i = 0; i < m.n; i++)
	{
		fin >> m.prices[i];
		fin >> m.dishes[i];
	}
}

Automata::~Automata()
{
	delete[] m.dishes;
	delete[] m.prices;
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
void Automata::setMenu(ifstream fin)
{
	if (m.dishes)
	{
		delete[] m.dishes;
		delete[] m.prices;

	}
	fin >> m.n;
	m.dishes = new string[m.n];
	m.prices = new int[m.n];
	for (int i = 0; i < m.n; i++)
	{
		fin >> m.prices[i];
		fin >> m.dishes[i];
	}
}

bool Automata::check()
{
	if (chosenNum == -1) return false;
	return cash == (m.prices[chosenNum]);
}
returns Automata::cook()
{
	state = COOK;
	cout << "preparing..." << endl;
	state = READY;
	return CORRECT;
}
returns Automata::finish()
{
	if (state == READY)
	{
		cansel();
		return CORRECT;
	}
	return MISTAKE;
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

returns Automata::coin(int sum)
{
	if (state == WAIT)
	{
		state = ACCEPT;
	}

	if (state == ACCEPT)
	{
		cash += sum;
		return CORRECT;
	}

	return MISTAKE;
}
returns Automata::choise(int Num)
{	

	if ((Num >= m.n) || (Num < 0))
	{
		return MISTAKE;
	}
	chosenNum = Num;
	if (check())
	{
		cook();
	}
	return CORRECT;
}
returns Automata::cansel()
{
	if (state == OFF)
	{
		return MISTAKE;
	}
	cash = 0;
	chosenNum = -1;
	state = WAIT;
	return CORRECT;
}