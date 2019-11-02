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

void printFile(std::string file){
  std::ifstream fin = stream_file(file);
  std::string line;
  while(getline(fin, line)) std::cout << line << std::endl;
  std::cout << std::endl;
  fin.close();
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
     organized: return all stylized lines as one string
  */
  std::string line, noSpacesLine, cleaned, organized;
  int indents = 0;
  while(getline(fin, line)){
    noSpacesLine = removeLeadingSpaces(line);
    if (noSpacesLine[0]== '}'){ //removes one indent if  the first thing in the line is a closing bracket
       indents -= 1;
       cleaned = tabs(indents) + noSpacesLine + '\n';
       indents += 1;
    }
    else cleaned = tabs(indents) + noSpacesLine + '\n';
    organized += cleaned;

    indents -= countChar(line, '}');
    indents += countChar(line, '{');
  }
  fin.close();
  return organized;
}
