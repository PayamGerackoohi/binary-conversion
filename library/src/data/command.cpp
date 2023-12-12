#include "data/command.hpp"

std::string toString(const Command &command) {
  switch (command) {
  case Command::Convert:
    return "Convert";
  case Command::None:
    return "None";
  default:
    return "[Unknwon]";
  }
}

std::ostream &operator<<(std::ostream &os, const Command &command) {
  os << toString(command);
  return os;
}
