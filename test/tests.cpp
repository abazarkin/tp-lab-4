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
TEST(automata, test_1)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    EXPECT_EQ(aut->getState(), OFF);
}

TEST(automata, test_2)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    EXPECT_EQ(aut->getState(), WAIT);
}

TEST(automata, test_3)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->off();
    EXPECT_EQ(aut->getState(), OFF);
}

TEST(automata, test_4)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(1);
    EXPECT_EQ(aut->getState(), ACCEPT);
}

TEST(automata, test_5)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(1);
    aut->cancel();
    EXPECT_EQ(aut->getState(), WAIT);
}

TEST(automata, test_6)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    aut->check(4);
    EXPECT_EQ(aut->getState(), COOK);
}

TEST(automata, test_7)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    aut->check(6);
    EXPECT_EQ(aut->getState(), WAIT);
}

TEST(automata, test_12)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(1);
    unsigned int* cond = nullptr;
    EXPECT_EQ(aut->choice(0, cond, 0), 0);
}

TEST(automata, test_13)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(3);
    unsigned int* cond = nullptr;
    EXPECT_EQ(aut->choice(1, cond, 0), 1);
}

TEST(automata, test_14)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(5);
    unsigned int* cond = nullptr;
    EXPECT_EQ(aut->choice(2, cond, 0), 2);
}

TEST(automata, test_15)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(5);
    unsigned int* cond = nullptr;
    EXPECT_EQ(aut->choice(3, cond, 0), 1);
}

TEST(automata, test_16)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(2);
    unsigned int* cond = {0};
    EXPECT_EQ(aut->choice(0, cond, 1), 0);
}

TEST(automata, test_17)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(5);
    unsigned int* cond = {1};
    EXPECT_EQ(aut->choice(1, cond, 1), 1);
}

TEST(automata, test_18)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(10);
    unsigned int* cond = {2};
    EXPECT_EQ(aut->choice(2, cond, 1), 4);
}

TEST(automata, test_19)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->coin(10);
    unsigned int* cond = {0, 1};
    EXPECT_EQ(aut->choice(2, cond, 2), 4);
}

TEST(automata, test_20)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    EXPECT_EQ(aut->getCash(), 5);
}

TEST(automata, test_21)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    EXPECT_EQ(aut->finish(), 5);
}

TEST(automata, test_22)
{
    string bev_menu[4] = {"Espresso", "Dark roast", "Hot chocolate", "House blend"};
    string con_menu[3] = {"Milk", "Sugar", "Mocha"};
    unsigned int bev_cost[4] = {1, 2, 3, 4};
    unsigned int con_cost[3] = {1, 2, 3};
    Automata* aut = new Automata(bev_cost, con_cost, bev_menu, con_menu);
    aut->on();
    aut->coin(5);
    EXPECT_EQ(aut->cook(bev_cost[1], bev_menu[1]), 3);
}
