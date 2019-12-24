//
// Created by Илья Соловьёв on 02.12.2019.
//

#include "Automata.h"
#include <vector>
#include <string>

int main() {
    vector<string> menu(0);
    menu.push_back("Tea");
    menu.push_back("Cappuchino");
    menu.push_back("Americano");

    vector<int> prices(0);
    prices.push_back(20);
    prices.push_back(50);
    prices.push_back(40);
    prices.push_back(50);
    Automata coffeeMashine(menu, prices);

    int user;
    do {
        cout
                << "\tWhat to do with coffeeMashine?\n1) Turn on\n2) Insert money\n3) Take money back\n4) Choose a drink\n5) Turn off\n\nEnter a number:";
        cin >> user;
        switch (user) {
            case 1: {
                coffeeMashine.on();
                break;
            }
            case 2: {
                if (coffeeMashine.printState() == WAIT) {
                    cout << "Insert a bill or coin" << endl;
                    int cash;
                    cin >> cash;
                    coffeeMashine.coin(cash);
                } else {
                    cout << "Wrong command" << endl;
                }
                break;
            }
            case 3: {
                if (coffeeMashine.printState() == ACCEPT || coffeeMashine.printState() == WAIT) {
                    int cashback = coffeeMashine.cancel();
                    cout << "Take your cashback: " << cashback << endl;
                } else {
                    cout << "Wrong command" << endl;
                }
                break;
            }
            case 4: {
                if (coffeeMashine.printState() == ACCEPT) {
                    cout << "Your balance: " << coffeeMashine.getCash() << endl;
                    coffeeMashine.printMenu();
                    cout << "Enter a number of a drink" << endl;
                    int choice;
                    cin >> choice;
                    choice -= 1;
                    if (coffeeMashine.choice(choice)) {
                        if (coffeeMashine.check(choice)) {
                            coffeeMashine.cook(choice);
                            int cashback = coffeeMashine.finish(choice);
                            cout << "Take your cashback: " << cashback << endl;
                        } else {
                            cout << "Not enough money" << endl;
                        }
                    } else {
                        cout << "Wrong choice - no such drink" << endl;
                    }
                } else {
                    cout << "Wrong command" << endl;
                }
                break;
            }
            case 5: {
                coffeeMashine.off();
                break;
            }
        }

    } while (user != -1);


    return 0;
}