#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Test removeLeadingSpaces(string line"){
	CHECK(removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  ");
}

TEST_CASE("Test countChar(string line, char c)"){
	CHECK(countChar("int main(){", '{') == 1);
}

TEST_CASE("unindent Test"){
   CHECK(indentedParse("bad-code.cpp") == "int main(){\n\t// Hi, I'm a program!\n\tint x = 1; \n\tfor(int i = 0; i < 10; i++) {\n\t\tcout << i;\n\t\tcout << endl;\n\t}\n}");
}
