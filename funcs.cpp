#include <iostream>
#include <string>
#include <cctype>

std::string removeLeadingSpaces(std::string line){
  std::string removedLine;
  int i = 0;
  bool foundSpace = false;
  while(line[i]){
    char c = line[i];
    while(foundSpace) {
      if(!isspace(c)){
	removedLine += c;
	foundSpace = true;
      }
    }
    removedLine += line[i];
  }
  return removedLine;
}
