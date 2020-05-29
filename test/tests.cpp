#include "gtest/gtest.h"
#include "automata.h"

#include <string>
#include <vector>

TEST(automata, no_menu)
{
   std::vector<std::string> menu = {};
	std::vector<int>        prise = {};

   Automata automata(menu, prise);

   const char* expect       ="NODRINKS";
   std::string get    = automata.getState();

   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, stay_off)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {0};

   Automata automata(menu, prise);

   const char* expect = "OFF";
   std::string get;    
   
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());

   automata.coin(0);
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
	automata.choise(0);
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
	automata.cancel();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
	automata.cook();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, turn_on)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {0};

   Automata automata(menu, prise);

   const char* expect = "WAIT";
   std::string get;    
   
   automata.on();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, get_coins)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {0};

   Automata automata(menu, prise);

   const char* expect = "ACCEPT";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, out_of_menu)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {0};

   Automata automata(menu, prise);

   const char* expect = "ACCEPT";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   automata.choise(2);
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, in_menu)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {0};

   Automata automata(menu, prise);

   const char* expect = "CHECK";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   automata.choise(0);
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, not_enough_money)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {13};

   Automata automata(menu, prise);  
   
   automata.on();
   automata.coin(12);
   automata.choise(0);
   ASSERT_FALSE(automata.check());
}

TEST(automata, enough_money)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {11};

   Automata automata(menu, prise);   
   
   automata.on();
   automata.coin(12);
   automata.choise(0);
   ASSERT_TRUE(automata.check());
}

TEST(automata, not_enough_money_try_to_cook)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {13};

   Automata automata(menu, prise);

   const char* expect = "CHECK";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   automata.choise(0);
   automata.cook();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, choose_without_cancel)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {13};

   Automata automata(menu, prise);

   const char* expect = "COOK";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   automata.cancel();
   automata.coin(15);
   automata.choise(0);
   automata.cook();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, choose_with_cancel)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {13};

   Automata automata(menu, prise);

   const char* expect = "COOK";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   automata.cancel();
   automata.coin(15);
   automata.choise(0);
   automata.cook();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}

TEST(automata, finish_cook)
{
   std::vector<std::string> menu = {"smt"};
	std::vector<int>        prise = {13};

   Automata automata(menu, prise);

   const char* expect = "WAIT";
   std::string get;    
   
   automata.on();
   automata.coin(12);
   automata.cancel();
   automata.coin(15);
   automata.choise(0);
   automata.cook();
   automata.finish();
   get = automata.getState();
   EXPECT_STREQ(expect, get.c_str());
}