#include <Conjugation.h>
#include <Generator.h>
#include <iostream>

int main(int argc, char * argv[]) {
  if (argc != 2) {
    printf("usage: verb filename\n");
    return 0;
  }

  Conjugation conj;
  auto list = conj.loadFile(argv[1]);
  Generator gen(list.size());

  conj.printVerbs(true);

  auto verb = conj.VerbList[0];
  printf("%s\n", verb.conjugation(0,0).c_str());

  for (int i = 0; i < 10; i++)
    printf("%d %d %d\n", gen.getVerb(), gen.getTense(), gen.getPerson());


  return 0;
}
