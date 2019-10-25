#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
  std::string inden = indentedParse();
  std::cout << inden << std::endl;
  return 0;
}
