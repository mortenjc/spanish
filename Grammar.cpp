
#include <Grammar.h>

std::map <std::string, int> Grammar::tenses = {
  {"PRES", 0}, {"PRET", 1}, {"IMP",  2}, {"COND", 3}, {"FUT",  4}
};

std::vector<std::string> Grammar::tensesText = {
  "PRES", "PRET", "IMP", "COND", "FUT"
};

std::vector<std::string> Grammar::tensesQText = {
  "", "", "used to", "would", "will"
};

std::map <std::string, int> Grammar::persons = {
  {"1s", 0}, {"2s", 1}, {"3s", 2}, {"1p", 3}, {"2p", 4}, {"3p", 5}
};

std::vector <std::string> Grammar::personsText = {
  "1s", "2s", "3s", "1p", "2p", "3p"
};

std::vector <std::string> Grammar::personsQText = {
  "I", "you", "he/she/it", "we", "you(pl)", "they"
};

// Regular -ar
std::vector <std::vector<std::string>> Grammar::regular_ar =
{
  {"o",    "as",    "a",    "amos",    "áis",     "an"   }, // Present
  {"é",    "aste",  "ó",    "amos",    "asteis",  "aron" }, // Preterite
  {"aba",  "abas",  "aba",  "abamos",  "abais",   "aban" }, // Imperfect
  {"aría", "arías", "aría", "aríamos", "aríais",  "arían"}, // Conditional
  {"aré",  "arás",  "ará",  "aremos",  "aréis",   "arán" }, // Future
};

// Regular -ir/-er
std::vector <std::vector<std::string>> Grammar::regular_ir =
{
  {"o",    "es",    "e",    "imos",    "ís",      "en"    }, // Present
  {"í",    "iste",  "ió",   "imos",    "isteis",  "ieron" }, // Preterite
  {"ía",   "ías",   "ía",   "íamos",   "íais",    "ían"   }, // Imperfect
  {"iría", "irías", "iría", "iríamos", "iríais",  "irían"}, // Conditional
  {"iré",  "irás",  "irá",  "iremos",  "iréis",   "irán" }, // Future
};
