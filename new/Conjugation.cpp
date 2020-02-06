#include <Conjugation.h>
#include <fstream>
#include <sstream>

//
void Conjugation::printVerbs(bool Long) {
  for (auto & Verb : VerbList) {
    Verb.print(Long);
  }
}


//
std::vector<Verb> & Conjugation::loadFile(std::string FileName) {
  Verb TmpVerb;
  std::ifstream infile(FileName);
  std::string line;
  int LineNum{0}, State{0}, Entries{0};
  while (std::getline(infile, line)) {
    LineNum++;

    std::istringstream iss(line);
    std::string a, b, c, d, e, f;
    if (!(iss >> a >> b >> c >> d >> e >> f)) {
      printf("Error loading file in line %d\n", LineNum);
      break;
    }
    // printf("%s %s %s %s %s %s\n", a.c_str(), b.c_str(), c.c_str(),
    //                               d.c_str(), e.c_str(), f.c_str());

    std::vector<std::string> conjug{a, b, c, d, e, f};

    switch (State) {
      case 0: // Expect a == #
        if (a != "#") {
          printf("Header error in line %d\n", LineNum);
          return VerbList;
        }
        Entries = stoi(d);
        State++;
        break;

      case 1: // Read basic verb properties
        TmpVerb.Infinitive = a;
        TmpVerb.PresentParticiple = e;
        TmpVerb.PastParticiple = f;
        if (b == "regular") {
          TmpVerb.Regular = true;
        } else {
          TmpVerb.Regular = false;
        }
        TmpVerb.Conjug.clear();
        State++;
        break;

      case 2: // Present
      case 3: // Preterite
      case 4: // Incomplete
      case 5: // Conditional
      case 6: // Future
        TmpVerb.Conjug.push_back(conjug);
        State++;
        break;
    }

    // All is good, append to list
    if (State == 7) {
      VerbList.push_back(TmpVerb);
      State = 0;
    }
  }

  if (VerbList.size() != Entries) {
    printf("entry mismatch, expected %d got %lu\n", Entries, VerbList.size());
  }
  return VerbList;
}
