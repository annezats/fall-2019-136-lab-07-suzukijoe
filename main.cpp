#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
  std::string str;
  std::cin >> str;
  std::cout << std::endl;
  
  std::string result = removeLeadingSpaces(str);
  int brackets = countChar(str, '{');
  std::cout << result << std::endl;
  std::cout << brackets << std::endl;  
  return 0;
}
