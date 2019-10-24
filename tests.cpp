#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Test removeLeadingSpaces(string line"){
	CHECK(removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  ");
}

