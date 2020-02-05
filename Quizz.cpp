
#include <Quizz.h>
#include <Grammar.h>
#include <Trace.h>

Quizz::Quizz(std::vector<Verb::VerbTuple> & vocabulary)
   : Vocabulary(vocabulary) { }

std::string Quizz::makeQuestion(Verb::VerbTuple & vt, int tense, int person) {
  auto question = vt.VerbName;
  question += " (" + Grammar::personsText[person] + " " + Grammar::tensesText[tense];
  question +=  ") - to " + vt.Present; // infinitive?
  question += "\n" + Grammar::personsQText[person] + " " + Grammar::tensesQText[tense] + " ";
  if (tense == 1)
    question += vt.Past;
  else
    question += vt.Present;
  question += " every day." ;
  return question;
}

void Quizz::printStats() {
  if (stats.NumberofQuestions == 0)
    return;

  printf("You got %.0f%% correct (%d out of %d)\n",
         100.0 * stats.CorrectAnswers/stats.NumberofQuestions,
         stats.CorrectAnswers, stats.NumberofQuestions);
  printf("Your longest streak was %d\n", stats.MaxStreak);
}


Verb::VerbTuple Quizz::find(std::string verb) {
  Verb::VerbTuple unfound {"X", "X", "X"};
  for (auto & tuple : Vocabulary) {
    if (verb.compare(tuple.VerbName) == 0)
      return tuple;
  }
  return unfound;
}
