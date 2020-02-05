
#include <Verb.h>
#include <Trace.h>
#include <fstream>
#include <stdio.h>
#include <wchar.h>

/// \brief count nonprintable chars for correct alignment of printf
int Verb::l(std::string string) {
    const char * str = &string[0];
    int len = 0;

    while (*str != '\0') {
        if ((*str & 0xc0) == 0x80) {
            len++;
        }
        str++;
    }
    return len;
}


///
std::vector<Verb::VerbTuple> Verb::loadfile(std::string filename) {
  std::vector<Verb::VerbTuple> result;
  std::ifstream infile(filename);
  std::string verb, pres, pret;

  while (infile >> verb >> pres >> pret) {
    trace.trace("Adding verb %s", verb);
    Verb::VerbTuple tuple(verb, pres, pret);
    result.push_back(tuple);
  }
  return result;
}


Verb::VerbTuple Verb::findVerb(std::string verb, std::vector<Verb::VerbTuple> verbList) {
  Verb::VerbTuple res("", "", "");
  for (auto & vt : verbList) {
    if (vt.VerbName.compare(verb) == 0) {
      res = vt;
      break;
    }
  }
  return res;
}

///
bool Verb::isAr(std::string infinitive) {
  if (infinitive.size() < 2) {
    return false;
  }

  auto end = infinitive.substr(infinitive.size() - 2, 2);

  if (end.compare("ar") == 0) {
    return true;
  }
  return false;
}

///
bool Verb::isIrEr(std::string infinitive) {
  if (infinitive.size() < 2) {
    return false;
  }

  auto end = infinitive.substr(infinitive.size() - 2, 2);

  if ((end.compare("ir") == 0) or (end.compare("er") == 0)) {
    return true;
  }
  return false;
}

///
std::string Verb::conjugate(std::string verb) {
  if ((not isAr(verb)) and (not isIrEr(verb)))
    return " - unrecognizable verb - ";

  auto root = verb.substr(0, verb.size() - 2); // remove ar ir er

  auto m = Grammar::regular_ar;
  if (isIrEr(verb))
    m = Grammar::regular_ir;

  for (int p=0; p < 6; p++) {
    for (int t=0; t < 5; t++) {
      auto conj = root + m[t][p];
      printf("%-*s", 20 + l(conj), conj.c_str());
    }
    printf("\n");
  }
  return "";
}

std::string Verb::conjugate(std::string verb, std::string tense, std::string person) {
  if ((not isAr(verb)) and (not isIrEr(verb)))
    return "unknown";

  auto root = verb.substr(0, verb.size() - 2); // remove ar ir er

  auto m = Grammar::regular_ar;
  if (isIrEr(verb))
    m = Grammar::regular_ir;

  return root + m[Grammar::tenses[tense]][Grammar::persons[person]];
}
