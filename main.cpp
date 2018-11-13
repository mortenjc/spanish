#include <Verb.h>
#include <Quizz.h>
#include <iostream>
#include <random>

int main(int argc, char * argv[]) {

  Verb verb;
  auto list = verb.loadfile(argv[1]);
  Quizz quizz(list);

  std::default_random_engine generator;
  std::uniform_int_distribution<int> pdist(0,5);
  std::uniform_int_distribution<int> tdist(0,4);

  for (auto & vt : list) {
    auto tense  = tdist(generator);
    auto person = pdist(generator);
    auto question = quizz.makeQuestion(vt, tense, person);

    printf("[%d/%d - streak %d] %s\n",
           quizz.stats.CorrectAnswers,
           quizz.stats.NumberofQuestions,
           quizz.stats.CurrStreak,
           question.c_str());
    printf("> ");


    auto answer = verb.conjugate(vt.VerbName, Grammar::tensesText[tense], Grammar::personsText[person]);
    std::string user_answer;
    std::cin >> user_answer;

    if (user_answer.compare("q") == 0) {
      quizz.printStats();
      return 0;
    }

    if (user_answer.compare(answer) == 0) {
      quizz.stats.correctAnswer();
    } else {
      quizz.stats.wrongAnswer();
    }
  }

  return 0;
}
