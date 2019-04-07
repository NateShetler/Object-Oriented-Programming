
#include "json.hpp"

#include <iterator>
#include <iostream>
#include <string>
#include <fstream> 

int
main(int argc, char* argv[])
{

  /*
  std::istreambuf_iterator<char> first(std::cin);
  std::istreambuf_iterator<char> last;
  std::string s(first, last);

  json::Value* val = json::parse(s);

  // std::cout << size(val) << ' ' << height(val) << '\n';
  std::cout << *val << '\n';
  */

  // Raw file string
  std::string fromFile = "";
  // Vector for Author and Titles
  std::vector<std::string> authorAndTitle{};

  std::ifstream inFile;
  inFile.open("cpp.json");

  if (inFile)
  {
    getline(inFile, fromFile);

  }
  else
  {
    // The file could not be opened so let them know
    std::cout << "The file could not be opened :(" << std::endl;
  }
}