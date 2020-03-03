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
}


#endif //__FACTORY_TEST_HPP__
