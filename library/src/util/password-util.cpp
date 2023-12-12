#include "util/password-util.hpp"
#include "constants.hpp"
#include "data/rune.hpp"
#include <sstream>

std::string expandPassword(Settings *settings) {
  char index = 1;
  std::stringstream ss;
  Rune rune(settings->password);
  while (index++ <= settings->expandedPasswordSize) {
    ss << char(index ^ rune.gen());
  }
  return ss.str();
}
