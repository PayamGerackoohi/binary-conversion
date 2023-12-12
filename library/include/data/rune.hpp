#ifndef RUNE_HPP
#define RUNE_HPP

#include <string>

class Rune {
public:
  Rune(std::string password);
  char gen();

private:
  int index;
  int size;
  std::string password;
};

#endif
