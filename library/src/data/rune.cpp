#include "data/rune.hpp"
#include "util/color.hpp"
#include <iostream>

Rune::Rune(std::string password)
    : password(std::move(password)), index(0), size(static_cast<int>(password.size())) {
  if (size == 0) {
    std::cerr << payam::red << "The password cannot be empty" << std::endl;
    exit(1);
  }
}

char Rune::gen() {
  char c = password[index];
  index++;
  if (index >= size)
    index -= size;
  return c;
}
