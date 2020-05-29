#include "automata.h"

	Automata::Automata()
	{
		cash = 0;
		state = OFF;
		drink = 0;
	}
	int Automata::on()
	{
		if (state == OFF)
		{
			state = WAIT;
			return 0;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}
	int Automata::off()
	{
		if (state == WAIT)
		{
			state = OFF;
			return 0;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}
	int Automata::coin(int coins)
	{
		if (state == WAIT || state == ACCEPT)
		{
			state = ACCEPT;
			cash += coins;
			return 0;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}
	int Automata::printMenu()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << i << ": " << menu[i] << " - " << prices[i] << endl;
		}
		return 0;
	}
	int Automata::printState()
	{
		switch (state)
		{
		case OFF:
			cout << "State = OFF" << endl;
			break;
		case WAIT:
			cout << "State = WAIT" << endl;
			break;
		case ACCEPT:
			cout << "State = ACCEPT" << endl;
			break;
		case CHECK:
			cout << "State = CHECK" << endl;
			break;
		case COOK:
			cout << "State = COOK" << endl;
			break;
		default:
			cout << "ERROR" << endl;
			return -1;
			break;
		}
		return 0;
	}

	int Automata::choice(int numb)
	{
		if (state == ACCEPT)
		{
			if (numb < 0 || numb > 4)
			{
				cout << "drink not exist" << endl;
				return 0;
			}
			if (prices[numb] > cash)
			{
				cout << "lack of money" << endl;
				return 0;
			}
			state = CHECK;
			drink = numb;
			return 0;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}

	int Automata::check()
	{
		if (state == CHECK )
		{
			cout << "cash = " << cash << " drink = " << drink << endl;
			return 0;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}

	int Automata::cancel()
	{
		if (state == CHECK || state == ACCEPT)
		{
			state = WAIT;
			int forRet = cash;
			cash = 0;
			return forRet;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}
	int Automata::cook()
	{
		if (state == CHECK)
		{
			state = COOK;
			cout << "drink ready" << endl;
			return drink;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}

	int Automata::finish()
	{
		if (state == COOK)
		{
			state = WAIT;
			int forRet = cash - prices[drink];
			drink = 0;
			cash = 0;
			return forRet;
		}
		else {
			cout << "ERROR\n";
			return -1;
		}
	}