#include "gtest/gtest.h"
#include <Automata.h>
// Beverages
#include "HouseBlend.h"
#include "Espresso.h"
#include "HotChocolate.h"
#include "DarkRoast.h"
// Condiments
#include "Milk.h"
#include "Mocha.h"
#include "Sugar.h"
#include <string>

// task1
TEST(automata, task1_1)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    EXPECT_EQ(aut->getState(), OFF);
}

TEST(automata, task1_2)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    EXPECT_EQ(aut->getState(), WAIT);
}

TEST(automata, task1_3)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->off();
    EXPECT_EQ(aut->getState(), OFF);
}

TEST(automata, task1_4)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(1);
    EXPECT_EQ(aut->getState(), ACCEPT);
}

TEST(automata, task1_5)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(1);
    aut->cancel();
    EXPECT_EQ(aut->getState(), WAIT);
}

TEST(automata, task1_6)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    EXPECT_EQ(aut->check(4), COOK);
}

TEST(automata, task1_7)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    int bev_cost[4] = {1, 2, 3, 4};
    int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    EXPECT_EQ(aut->check(5), WAIT);
}

