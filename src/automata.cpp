#include "automata.h"


Automata::Automata()
{
    cash = 0;
    state = WAIT;
}

void Automata::on()
{
    if(state == OFF){
        state = WAIT;
        cout << "You turned on that Automata" << endl;
    }
    else cout << "The Automata is already turned on" << endl;
}

int Automata::off()
{
    return cash;
    cash = 0;
    state = OFF;
    cout << "You turned off that Automata" << endl;
}

void Automata::coin(int money)
{
    if(state != OFF)
    {
        cash += money;
        cout << "Added " << money << "coins\n" << "You have " << cash << " coins on balance" << endl;
    }
    else cout << "Can`t add coin" << endl;
}

void Automata::PrintDrinks()
{
    if(state != OFF)
    {
        for(int i; i < drinks.size(); i++) cout << drinks[i] << "cost is " << prices[i] << endl;
    }
    else cout << "Automata is OFF" << endl;
}

void Automata::PrintState()
{
    cout << "Automata is in " << states[States(state)] << " mode" << endl;
}

int Automata::choice(int drink)
{
    if (check(drink))
    {
        cook(drink);
        int money = cash;
        money -= prices[drink];
        cout << "You have " << cash << " coins" << endl;
        return money;
    }
    else 
    {
        cout << "You don`t have enough coins" << endl;
    }

}

bool Automata::check(int drink)
{
    state = CHECK;
    if(cash >= prices[drink]) return true;
    else return false;
}

int Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state == WAIT;
		cout << "The operation is cancelled" << endl;
		return finish();
	}
	else
	{
		cout << "You can't cancel this operation" << endl;
		return 0;
	}
		
}

void Automata::cook(int drink)
{
    state = COOK;
    int money = cash;
    money -= prices[drink];
}

int Automata::finish()
{
    cout << "Take your coin back:" << cash << endl;
    return cash;
}
