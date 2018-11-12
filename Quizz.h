
#pragma once

#include <string>
#include <vector>
#include <Verb.h>
#include <Grammar.h>

class Quizz {
public:
  struct QnA {
    std::string verb;
    std::string tense;
    std::string person;
    std::string conjugation;
  };

  Quizz(std::vector<Verb::VerbTuple> & vocabulary);

  Verb::VerbTuple find(std::string);

  std::string makeQuestion(std::string verb, std::string tense, std::string person);

private:
  std::vector<Verb::VerbTuple> Vocabulary;
};
