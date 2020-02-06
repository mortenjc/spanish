
#pragma once

#include <string>
#include <vector>

class Verb {
public:
  bool Regular;
  std::string Infinitive; // Spanish name, ex: hacer
  std::string PresentParticiple; // (-ing) haciendo
  std::string PastParticiple; // (-ed) hecho
  std::vector<std::vector<std::string>> Conjug;


  // return conjugation given Tense and Person
  std::string conjugation(int Tense, int Person) {
    return Conjug[Tense][Person];
  }

  // Print the verb in short or long form
  void print(bool Long) {
      printf("\n%s (%s) %s, %s\n",
              Infinitive.c_str(),
              Regular ? "regular" : "irregular",
              PresentParticiple.c_str(),
              PastParticiple.c_str());
      if (Long) {
        for (auto & Conj : Conjug) {
          printf("%s %s %s %s %s %s\n",
            Conj[0].c_str(), Conj[1].c_str(), Conj[2].c_str(),
            Conj[3].c_str(), Conj[4].c_str(), Conj[5].c_str());
        }
    }
  }
};
