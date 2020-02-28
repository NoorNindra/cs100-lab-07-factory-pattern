#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "base.hpp"
#include "op.hpp"
#include "factory.hpp"

TEST(AddTestFact, AddFactory) {
	char one = '1';
	char* oneP = &one;
	char plus = '+';
	char* plusP = &plus;
	char five = '5';
	char* fiveP = &five;

	//char** array[3] = {oneP, plusP, fiveP};

	char** array;
	array[0] = oneP;
	array[1] = plusP;
	array[2] = fiveP;
	
	Factory* fact = new Factory();
	Base* base = fact->parse(array, 3);

	EXPECT_EQ(base->evaluate(), 6);
}


#endif //__FACTORY_TEST_HPP__
