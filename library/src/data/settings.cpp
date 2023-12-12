#include "data/settings.hpp"
#include "constants.hpp"
#include "util/color.hpp"
#include "util/file-util.hpp"

Settings::Settings() : command(Command::None), input(""), output(""), password(DEFAULT_PASSWORD), expandedPasswordSize(DEFAULT_EXPANDED_PASSWORD_SIZE) {}

std::ostream &operator<<(std::ostream &os, const Settings &s) {
  os << "Settings<"
     << "command<" << s.command << ">"
     << " input<" << s.input << ">"
     << " output<" << s.output << ">"
     << " password<" << s.password << ">"
     << " expandedPasswordSize<" << s.expandedPasswordSize << ">>";
  return os;
}

bool Settings::hasValidIO() {
  if (exists(input)) {
    if (output.empty())
      output = input;
    return true;
  }
  return false;
}
