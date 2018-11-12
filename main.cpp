#include <Verb.h>

int main(int argc, char * argv[]) {

  Verb verb;
  auto list = verb.loadfile(argv[1]);

  for (auto & vt : list) {
    printf("%s, %s, %s\n", vt.VerbName.c_str(), vt.Present.c_str(), vt.Past.c_str());
    verb.conjugate(vt.VerbName);
  }

  return 0;
}
