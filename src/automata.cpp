#include "automata.h"

string automata::menu[] = { "Cappuccino", "Macchiato", "Latte", "Espresso", "Americano", "Frapp?", "Tea", "Decaf", "Mocha" };
int automata::prices[] = { 35, 40, 35, 35, 35, 40, 30, 35, 40 };
int sugar[5] = { 0, 1, 2, 3, 4 };

automata::automata()
{
	cash = 0;
	state = OFF;
	drink_id = -1;
	sugar_id = 2;
	flag = 0;
}

int automata::on()
{
	if (state == OFF)
	{
		cout << "~~~ waiting ~~~\n";
		state = WAIT;
		cout << "Done, I'm ON. \n";
		printState();
		printMenu();
		cout << "Toss a coin to your Witcher! plz \n";
		return -1;
	}
	else
	{
		cout << "I'm already ON '''what's wrong with you?'''. (-.-;) \n";
		return 0;
	}
		
}

int automata::off()
{
	if (state == WAIT)
	{
		cout << "~~~ waiting ~~~ \n";
		state = OFF;
		cout << "Done, I'm OFF. (-.-) zzZ \n";
		printState();
		return -1;
	}
	else
	{
		cout << "You can't turn me OFF now. }:-D \n";
		return 1;
	}
}

int automata::coin(int money)
{
	if (state == WAIT || state == ACCEPT)
	{
		state = ACCEPT;
		printState();
		if (money > 0)
		{
			cash += money;
			cout << "Now, It's mine: " << cash << "\n";
			return -1;
		}
		else
		{
			cout << "Where's my money? Oo \n";
			return 2;
		}
	}
	else
	{
		cout << "You can't do this now. -.- \n";
		return 6;
	}
}

int automata::add_sugar()
{
	if (sugar_id < 4)
	{
		sugar_id++;
		return -1;
	}
	else
	{
		cout << "Sugar is unhealthy, that's enough for you -.- \n";
		return 3;
	}
}

int automata::remove_sugar()
{
	if (sugar_id > 0)
	{
		sugar_id--;
		return -1;
	}
	else
	{
		cout << "Sugar is already at 0 -.- \n";
		return 4;
	}
}

int automata::choice(int drink)
{	
	drink_id = drink;
	if (state == ACCEPT)
	{
		int menu_size = sizeof(menu) / sizeof(string);
		if (drink >= 0 && drink <= menu_size)
		{
			state = CHECK;
			printState();
			return -1;
		}
		else
		{
			cout << "Oh, c'mon, Just choose right number. -.- \n";
			return 5;
		}
	}
	else
	{
		cout << "You can't do this now. -.- \n";
		return 6;
	}
}

int automata::check()
{
	if (state == CHECK)
	{
		if (cash >= prices[drink_id])
		{
			cash -= prices[drink_id];
			//state = COOK;
			flag = 1;
			return -1;
		}
		else
		{
			cout << "Not enough money, give me your money Oo \n";
			return 7;
		}

	}
	else
	{
		cout << "You can't do this now. -.- \n";
		return 6;
	}
}

int automata::cancel()
{
	if (state == ACCEPT || (state == CHECK && flag == 0))
	{
		state = WAIT;
		printState();
		return -1;
	}
	else 
	{
		if (state == CHECK && flag == 1)
		{
			cash += prices[drink_id];
			state = WAIT;
			printState();	
			return -1;
		}
		else
		{
			cout << "You can't do this now. -.- (You are late) \n";
			return 6;
		}
	}
}

int automata::cook()
{
	if (state == CHECK && flag == 1)
	{
		state = COOK;
		cout << "~~~ cooking ~~~\n";
		printState();
		return -1;
	}
	else
	{
		cout << "You can't do this now. -.- \n";
		return 6;
	}

}

int automata::finish()
{
	if (state == COOK)
	{
		cout << "Enjoy your drink! ^^ \n";
		if (cash > 0) return_coins();
		state = WAIT;
		printState();
		return -1;
	}
	else
	{
		cout << "You can't do this now. -.- \n";
		return 6;
	}
}

int automata::printMenu()
{
	int menu_size_1 = sizeof(menu) / sizeof(string);
	int menu_size_2 = sizeof(prices) / sizeof(int);
	if (menu_size_1 == menu_size_2)
	{
		cout << "Menu: \n";
		for (int i = 0; i < menu_size_1; i++)
		{
			cout << i << " " << menu[i] << " - " << prices[i] << "\n";	
		}
		return 0;
	}
	else
	{
		cout << "Something is wrong with the menu \n";
		return 7;
	}
}

int automata::printState()
{
	switch (state)
	{
	case OFF:
		cout << "State: OFF \n";
		break;
	case WAIT:
		cout << "State: WAIT \n";
		break;
	case ACCEPT:
		cout << "State: ACCEPT \n";
		break;
	case CHECK:
		cout << "State: CHECK \n";
		break;
	case COOK:
		cout << "State: COOK \n";
		break;
	default:
		cout << "How did this happen ? \n";
		return 8;
	}
	return -1;
}

void automata::return_coins()
{
	cout << "Take your money: " << cash << "\n";
	cash = 0;
	sugar_id = 2;
	drink_id = -1;
	flag = 0;
}

void automata::printSugarLvl()
{
	cout << "Sugar lvl: " << sugar[sugar_id] << "\n";
	return;
}
