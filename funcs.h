#pragma once

std::ifstream stream_file(std::string file);
std::string removeLeadingSpaces(std::string line);
int countChar(std::string line, char c);
std::string tabs(int count);
std::string indentedParse(std::string file);
