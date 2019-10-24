#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
  std::cout << "Test" << std::endl;
  std::string result = removeLeadingSpaces("       int x = 1;  ");
  std::cout << result << std::endl;
  
  return 0;
}
