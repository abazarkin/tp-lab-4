#include "automata.h"



string firstmenu[]{ "exit", "on" };
string mainmenu[]{ "exit", "choise", "coin","takeCoffe","Cancel" };

int main()
{
	Automata Coffe;
		cout << "0 - " << firstmenu[0] << endl;
		cout << "1 - " << firstmenu[1] << endl;
		int answ;
		cin >> answ;
		if (answ)
		{
			bool WORK = true;
			Coffe.on();
			while (WORK)
			{
				answ = 0;

				if (Coffe.getState() != ERROR)
				{
					cout << "Ready for work!" << endl;
					menu m1;
					m1 = Coffe.getMenu();
					for (int i = 0; i < m1.n; i++)
					{
						cout << i + 1 << ") " << m1.dishes[i] << " " << m1.prices[i] << "p" << endl;
					}
					cout << "your balance: " << Coffe.getCash() << endl;
					for (int i = 0; i < 5; i++)
					{
						cout << i << " - " << mainmenu[i] << endl;
					}
					cin >> answ;
				}

				if (answ)
				{
					
					switch (answ)
					{
					case 1: //choise
						if (Coffe.getState() == WAIT)
						{
							cout << "Enter some money" << endl;
						}
						if ((Coffe.getState() == ACCEPT))
						{
							int Num;
							cout << "Choise: ";
							cin >> Num;
							Coffe.choise(Num);
						}
						if (Coffe.getState() == ACCEPT)
						{
							cout << "Enter some money" << endl;
						}
						
							break;
					case 2: // coin
						int sum;
						cout << "Coins: ";
						cin >> sum;
						Coffe.coin(sum);
						break;
					case 3: //takeCoffe
						if (Coffe.getState() == READY)
						{
							Coffe.finish();
						}
						else
						{
							cout << "Its empty here" << endl;
						}
						break;
					default:
						break;
					}

				}
				else
				{
					WORK = false;
					Coffe.off();
				}
				         
			}
			
			

		}
	

	return 0;
}