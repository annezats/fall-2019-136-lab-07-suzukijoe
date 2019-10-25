#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cctype>

/*
  Open file stream for std input
*/
std::ifstream stream_file(std::string file){
  std::ifstream fin(file);
  if (fin.fail()){
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  return fin; 
}

/*
  Remove the leading spaces before each 'line'
*/
std::string removeLeadingSpaces(std::string line){
  int leadingSpace = 0;
  while(isspace(line[leadingSpace]))
    leadingSpace++;
  return line.substr(leadingSpace);
}

/*
  Count the amount of char c in string line
*/
int countChar(std::string line, char c){
  int count = 0;
  for(char ch: line){
    if(ch == c) count++;
  }
  return count;
}

/*
  Returns 'count' amount of tabs
*/
std::string tabs(int count){
  std::string indents;
  for(int i = 0; i < count; i++) indents += '\t';
  return indents; 
}

/*
  Go through the file and style each line correctly
*/
std::string indentedParse(std::string file){
  std::ifstream fin = stream_file(file);
  /* 
     line: line of the file
     cleaned: stylized line
     organized: return each stylized line as one string
  */
  std::string line, cleaned, organized;
  int indents = 0; 
  while(getline(fin, line)){
    int closing = countChar(line, '}');
    if (closing > 0) indents -= closing;
    cleaned = tabs(indents) + removeLeadingSpaces(line) + '\n';
    organized += cleaned;
    indents += countChar(line, '{');
  }
  fin.close();
  return organized;
}
