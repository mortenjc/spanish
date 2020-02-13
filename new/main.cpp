#include <Conjugation.h>
#include <Generator.h>
#include <iostream>

std::vector <std::string> tenses = {
  "present", "preterite", "imperfect", "conditional", "future"
};

std::vector <std::string> persons = {
  "yo", "tu", "el/ella/usted", "nosotros", "vosotros", "ellos/ustedes"
};

int main(int argc, char * argv[]) {
  if (argc != 2) {
    printf("usage: verb filename\n");
    return 0;
  }

  Conjugation conj;
  auto list = conj.loadFile(argv[1]);
  Generator gen(list.size());

  //conj.printVerbs(true);

  //auto verb = conj.VerbList[0];
  //printf("%s\n", verb.conjugation(0,0).c_str());

  for (int i = 0; i < 10; i++) {
    auto v = conj.VerbList[gen.getVerb()];
    auto t = gen.getTense();
    auto p = gen.getPerson();
    auto c = v.conjugation(t, p);
    printf("%s %s%s (%s) - %s\n",
        persons[p].c_str(),
        v.Infinitive.c_str(),
        v.Regular ? "" : "*",
        tenses[t].c_str(),
        c.c_str());
  }

  return 0;
}
