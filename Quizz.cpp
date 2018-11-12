
#include <Quizz.h>

Quizz::Quizz(std::vector<Verb::VerbTuple> & vocabulary)
   : Vocabulary(vocabulary) { }

std::string Quizz::makeQuestion(std::string verb, std::string tense, std::string person) {
  auto vt = find(verb);
  std::string question = verb + " (" + person + ") - to " + vt.Present; // infinitive?
  question += "\n" + Grammar::personsText[person] + " ";
  if (tense.compare("PRET") == 0 or tense.compare("IMP") == 0 ) {
    question += vt.Past;
  } else {
    question += vt.Present;
  }
  question += " every day.";
  return question;
}


Verb::VerbTuple Quizz::find(std::string verb) {
  Verb::VerbTuple unfound {"X", "X", "X"};
  for (auto & tuple : Vocabulary) {
    if (verb.compare(tuple.VerbName) == 0)
      return tuple;
  }
  return unfound;
}
