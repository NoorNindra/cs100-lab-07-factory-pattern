#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

TEST(FactoryTest, AddFactory) {
        string userInput = "5+1";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;
        
	Factory* fact = new Factory();
	Base* base = fact->parse(ptr2, userInput.size());

	EXPECT_EQ(base->evaluate(), 6);
        EXPECT_EQ(base->stringify(), "5.000000 + 1.000000");
}

TEST(FactoryTest, OpFactory) {
        string userInput = "5";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 5);
        EXPECT_EQ(base->stringify(), "5.000000");
}

TEST(FactoryTest, PowFactory) {
        string userInput = "3**2";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 9);
        EXPECT_EQ(base->stringify(), "3.000000 ** 2.000000");
}

TEST(FactoryTest, AddSubFactory) {
        string userInput = "5+2-1";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 6);
        EXPECT_EQ(base->stringify(), "5.000000 + 2.000000 - 1.000000");
}

TEST(FactoryTest, MultDivFactory) {
        string userInput = "6/2*4";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 12);
        EXPECT_EQ(base->stringify(), "6.000000 / 2.000000 * 4.000000");
}

TEST(FactoryTest, PowAddFactory) {
        string userInput = "2**3+2";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 10);
        EXPECT_EQ(base->stringify(), "2.000000 ** 3.000000 + 2.000000");
}

TEST(FactoryTest, PowSubFactory) {
        string userInput = "2**3-2";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 6);
        EXPECT_EQ(base->stringify(), "2.000000 ** 3.000000 - 2.000000");
}

TEST(FactoryTest, PowMultFactory) {
        string userInput = "2**3*2";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 16);
        EXPECT_EQ(base->stringify(), "2.000000 ** 3.000000 * 2.000000");
}

TEST(FactoryTest, PowDivFactory) {
        string userInput = "2**3/2";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 4);
        EXPECT_EQ(base->stringify(), "2.000000 ** 3.000000 / 2.000000");
}



#endif //__FACTORY_TEST_HPP__
