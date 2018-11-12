
#include <gtest/gtest.h>
#include <Verb.h>

class VerbTest : public ::testing::Test {
 protected:
   Verb verb;
  // void SetUp() overide {}
  // void TearDown() override {}
};

TEST_F(VerbTest, RegularAr) {
  auto tense = Grammar::tenses["PRES"];
  auto person = Grammar::persons["1s"];
  ASSERT_EQ(Grammar::regular_ar[tense][person], "o");

  tense = Grammar::tenses["PRET"];
  person = Grammar::persons["1s"];
  ASSERT_EQ(Grammar::regular_ar[tense][person], "é");

  tense = Grammar::tenses["PRES"];
  person = Grammar::persons["2p"];
  ASSERT_EQ(Grammar::regular_ar[tense][person], "áis");

}

TEST_F(VerbTest, IsArIrEr) {
  ASSERT_FALSE(verb.isAr(""));
  ASSERT_FALSE(verb.isAr("a"));
  ASSERT_FALSE(verb.isAr("aa"));

  ASSERT_FALSE(verb.isIrEr(""));
  ASSERT_FALSE(verb.isIrEr("a"));
  ASSERT_FALSE(verb.isIrEr("aa"));

  ASSERT_FALSE(verb.isAr("comer"));
  ASSERT_FALSE(verb.isAr("come"));
  ASSERT_TRUE(verb.isAr("acabar"));

  ASSERT_FALSE(verb.isIrEr("acabar"));
  ASSERT_FALSE(verb.isIrEr("acaba"));
  ASSERT_TRUE(verb.isIrEr("comer"));
  ASSERT_TRUE(verb.isIrEr("subir"));

  ASSERT_TRUE(verb.isAr("señalar"));
  ASSERT_FALSE(verb.isIrEr("señalar"));
}

TEST_F(VerbTest, ConjugateEscribir) {
  std::string v = "escribir";
  verb.conjugate(v);
  ASSERT_EQ(verb.conjugate(v, "PRES", "1s"), "escribo");
  ASSERT_EQ(verb.conjugate(v, "PRES", "2s"), "escribes");
  ASSERT_EQ(verb.conjugate(v, "PRES", "3s"), "escribe");
  ASSERT_EQ(verb.conjugate(v, "PRES", "1p"), "escribimos");
  ASSERT_EQ(verb.conjugate(v, "PRES", "2p"), "escribís");
  ASSERT_EQ(verb.conjugate(v, "PRES", "3p"), "escriben");

  ASSERT_EQ(verb.conjugate(v, "PRET", "1s"), "escribí");
  ASSERT_EQ(verb.conjugate(v, "PRET", "2s"), "escribiste");
  ASSERT_EQ(verb.conjugate(v, "PRET", "3s"), "escribió");
  ASSERT_EQ(verb.conjugate(v, "PRET", "1p"), "escribimos");
  ASSERT_EQ(verb.conjugate(v, "PRET", "2p"), "escribisteis");
  ASSERT_EQ(verb.conjugate(v, "PRET", "3p"), "escribieron");
}

TEST_F(VerbTest, ConjugateComprar) {
  std::string v = "comprar";
  verb.conjugate(v);
  ASSERT_EQ(verb.conjugate(v, "PRES", "1s"), "compro");
  ASSERT_EQ(verb.conjugate(v, "PRES", "2s"), "compras");
  ASSERT_EQ(verb.conjugate(v, "PRES", "3s"), "compra");
  ASSERT_EQ(verb.conjugate(v, "PRES", "1p"), "compramos");
  ASSERT_EQ(verb.conjugate(v, "PRES", "2p"), "compráis");
  ASSERT_EQ(verb.conjugate(v, "PRES", "3p"), "compran");

  ASSERT_EQ(verb.conjugate(v, "PRET", "1s"), "compré");
  ASSERT_EQ(verb.conjugate(v, "PRET", "2s"), "compraste");
  ASSERT_EQ(verb.conjugate(v, "PRET", "3s"), "compró");
  ASSERT_EQ(verb.conjugate(v, "PRET", "1p"), "compramos");
  ASSERT_EQ(verb.conjugate(v, "PRET", "2p"), "comprasteis");
  ASSERT_EQ(verb.conjugate(v, "PRET", "3p"), "compraron");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
