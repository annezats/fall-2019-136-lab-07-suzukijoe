#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
  std::cout << "Bad Code Style:" << std::endl;
  printFile("bad-code.cpp");

  std::cout << "Correct Style:" << std::endl;
  std::string inden = indentedParse("bad-code.cpp");
  std::cout << inden << std::endl;
  return 0;
}
