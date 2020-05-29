#include "gtest/gtest.h"
#include "Automata.h"


TEST(lab4, test1)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    unsigned int current_cash = Coffee.coin(30);    
    unsigned int result=30;
    EXPECT_EQ(current_cash, result);
}

TEST(lab4, test2)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(30);
	Coffee.coin(2);
    unsigned int return_cash = Coffee.cancel();
	unsigned int result=32;
    EXPECT_EQ(return_cash, result);
}

TEST(lab4, test3)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(30);
    Coffee.printMenu();
    Coffee.cancel();
    bool recall = Coffee.choice(2);
	bool result = false;
    EXPECT_EQ(recall, result);
	
}

TEST(lab4, test4)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(30);
    Coffee.printMenu();
    bool recall = Coffee.choice(2);
	bool result = true;
    EXPECT_EQ(recall, result);
	
}

TEST(lab4, test5)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(9);
    Coffee.printMenu();
    bool recall = Coffee.choice(1);
	bool result = false;
    EXPECT_EQ(recall, result);
	
}

TEST(lab4, test6)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(9);
    Coffee.printMenu();
	Coffee.coin(1);
    bool recall = Coffee.choice(1);
	bool result = true;
    EXPECT_EQ(recall, result);
	
}

TEST(lab4, test7)
{
	Automata Coffee({{"Water", 10}, {"Black Coffee", 30}, {"Tea", 15}});
    Coffee.on();
    Coffee.coin(30);
    bool recall = Coffee.check(3);
	bool result = true;
    EXPECT_EQ(recall, result);
	
}