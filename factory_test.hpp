#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

TEST(AddTestFact, AddFactory) {
        string userInput = "5+1";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;
        
	Factory* fact = new Factory();
	Base* base = fact->parse(ptr2, userInput.size());

	EXPECT_EQ(base->evaluate(), 6);
        EXPECT_EQ(base->stringify(), "5.000000 + 1.000000");
}

TEST(OpTestFact, AddFactory) {
        string userInput = "5";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 5);
        EXPECT_EQ(base->stringify(), "5.000000");
}

TEST(PowTestFact, AddFactory) {
        string userInput = "4**2";
        char* ptr1 = &userInput[0];
        char** ptr2 = &ptr1;

        Factory* fact = new Factory();
        Base* base = fact->parse(ptr2, userInput.size());

        EXPECT_EQ(base->evaluate(), 8);
        EXPECT_EQ(base->stringify(), "4.000000 ** 2.000000");
}




#endif //__FACTORY_TEST_HPP__
