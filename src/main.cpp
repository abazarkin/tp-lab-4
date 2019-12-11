#include "C:\Users\nuald\source\repos\tp-lab-4\include\automata.h"




string firstmenu[]{ "exit", "on" };
string mainmenu[]{ "exit", "choise", "coin","takeCoffe","Admin" };

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
				switch (Coffe.getState())
				{
				case WAIT: cout << "Ready for work!" << endl;
					break;
				case ERROR: cout << "ERROR" << endl;
				default:
					break;
				}
				for (int i = 0; i < 5; i++)
				{
					cout << i << " - " << mainmenu[i] << endl;
				}
				cin >> answ;
				         
			}
			
			

		}
	

	return 0;
}