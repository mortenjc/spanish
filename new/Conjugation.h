
#pragma once
#include <Verb.h>
#include <string>
#include <vector>

class Conjugation {
public:

  // load text file into VerbList
  std::vector<Verb> & loadFile(std::string FileName);

  // loop through VerbList and print entries
  void printVerbs(bool Long);

  // One entry for each verb in list
  std::vector<Verb> VerbList;
};
