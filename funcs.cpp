#include <iostream>
#include <string>
#include <cctype>

std::string removeLeadingSpaces(std::string line){
  std::string removedLine;
  bool foundSpace = true;
  for(char c: line){
    if(foundSpace) {
      if(!isspace(c)){
	removedLine += c;
	foundSpace = false;
      }
    } else removedLine += c;
  }
  return removedLine;
}

