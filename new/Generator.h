#include <random>

class Generator {
public:
  Generator(int Entries) {
    vdist = std::uniform_int_distribution<int>(0, Entries - 1);
  }

  int getVerb() {
    return vdist(generator);
  }

  int getTense() {
    return tdist(generator);
  }

  int getPerson() {
    return pdist(generator);
  }

private:
  std::default_random_engine generator;
  std::uniform_int_distribution<int> pdist{0,5};
  std::uniform_int_distribution<int> tdist{0,4};
  std::uniform_int_distribution<int> vdist{0,1};
};
