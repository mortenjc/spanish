
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

  struct Stats {
    int CorrectAnswers;
    int NumberofQuestions;
    int CurrStreak;
    int MaxStreak;

    void correctAnswer() {
      printf("correct!\n");
      NumberofQuestions++;
      CorrectAnswers++;
      CurrStreak++;
      if (CurrStreak > MaxStreak) {
        MaxStreak = CurrStreak;
      }
    }

    void wrongAnswer() {
      printf("sorry!\n");
      NumberofQuestions++;
      CurrStreak = 0;
    }
  };

  Quizz(std::vector<Verb::VerbTuple> & vocabulary);

  Verb::VerbTuple find(std::string);

  std::string makeQuestion(Verb::VerbTuple & vt, int tense, int person);

  void printStats();

  struct Stats stats;
private:
  std::vector<Verb::VerbTuple> Vocabulary;

};
