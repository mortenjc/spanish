
#include <gtest/gtest.h>

#include <Quizz.h>
#include <Grammar.h>

std::vector<struct Quizz::QnA> QuizzData {
  {"escribir",    "PRES",   "1s",   "escribo"},
  {"hablar",      "PRET",   "2p",   "hablasteis"},
  {"comprender",  "IMP",    "3s",   "comprendía"},
  {"sufrir",      "COND",   "1p",   "sufriríamos"},
  {"resultar",    "FUT",    "2s",   "resultarás"},
  {"correr",      "PRES",   "3p",   "corren"}
};

class QuizzTest : public ::testing::Test {
 protected:
};

TEST_F(QuizzTest, CheckQuizzData) {
  Verb myverb;
  auto vocab = myverb.loadfile("RegularVerbs.txt");
  Quizz myquizz(vocab);

  for (auto & entry : QuizzData) {
    auto vt = myverb.findVerb(entry.verb, vocab);
    auto res = myquizz.makeQuestion(vt, Grammar::tenses[entry.tense], Grammar::persons[entry.person]);
    printf("%s\n", res.c_str());
    ASSERT_EQ(myverb.conjugate(entry.verb, entry.tense, entry.person), entry.conjugation);
  }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
