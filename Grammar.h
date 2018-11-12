
#pragma once

#include <map>
#include <string>
#include <vector>

class Grammar {
public:
  static std::map <std::string, int> tenses;
  static std::map <std::string, int> persons;
  static std::map <std::string, std::string> personsText;
  static std::vector <std::vector<std::string>> regular_ar;
  static std::vector <std::vector<std::string>> regular_ir;
};
