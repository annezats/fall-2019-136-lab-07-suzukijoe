#include <iostream>
#include <string>
#include <cctype>

std::ifstream stream_file() {
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		 std::cerr << "File cannot be opened for reading." << std::endl;
		 exit(1); // exit if failed to open the file
	}

	std::string junk;        // new string variable
	getline(fin, junk); // read one line from the file

	return fin; 
}

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

int countChar(std::string line, char c){
  int count = 0;
  for(char ch: line) {
    if(ch == c) {
      count++;
    }
  }
  return count;
}

std::string parse(std::string file){
  
}
