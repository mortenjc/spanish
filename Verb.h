
#pragma once

#include <vector>
#include <string>
#include <Grammar.h>

class Verb {
public:
  struct VerbTuple {
    std::string VerbName;
    std::string Present;
    std::string Past;
    VerbTuple(std::string verb, std::string pres, std::string pret)
       : VerbName(verb), Present(pres), Past(pret) {};
  };

  std::vector<VerbTuple> loadfile(std::string filename);
  bool isAr(std::string infinitive);
  bool isIrEr(std::string infinitive);
  std::string conjugate(std::string);
  std::string conjugate(std::string verb, std::string tense, std::string person);

private:
  int l(std::string string);
};
