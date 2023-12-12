#include "util/color.hpp"

namespace payam {

Color::Color(std::string value) : value(value) {}

std::ostream &operator<<(std::ostream &os, Color &c) {
  os << "\033[1;" << c.value << "m";
  return os;
}

} // namespace payam
