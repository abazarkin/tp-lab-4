#include "automata.h"

int main()
{
	int money, num, l = -1;
	automata lulerz = automata();
	lulerz.on();
	//cin >> money;
	lulerz.coin(100);
	lulerz.add_sugar();
	lulerz.printSugarLvl();
	//cout << "Drink number?" << "\n";
	//cin >> num;
	if (lulerz.choice(5) != -1) 
	{ 
		lulerz.cancel();
	}
	else {
		if (lulerz.check() == -1)
		{
			lulerz.cook();
			lulerz.finish();
		}
		else
		{
			lulerz.cancel();
			lulerz.return_coins();
		}
	}
	lulerz.off();
	return 0;
}
