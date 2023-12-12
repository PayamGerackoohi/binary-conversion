#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "command.hpp"
#include <ostream>
#include <string>

struct Settings {
  explicit Settings();
  bool hasValidIO();
  std::string input;
  std::string output;
  std::string password;
  int expandedPasswordSize;
  Command command;
};

std::ostream &operator<<(std::ostream &os, const Settings &s);

#endif
