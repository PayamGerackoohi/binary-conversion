#ifndef PAYAM_COLOR_HPP
#define PAYAM_COLOR_HPP

#include <iostream>
#include <ostream>
#include <string>

namespace payam {

struct Color {
  std::string value;

  Color(std::string value);
  friend std::ostream &operator<<(std::ostream &, Color &);
} inline reset("0"), black("30"), red("31"), green("32"), yellow("33"), blue("34"), magenta("35"), cyan("36"), white("37"), BLACK("40"), RED("41"), GREEN("42"), YELLOW("43"), BLUE("44"), MAGENTA("45"), CYAN("46"), WHITE("47"), blackBright("90"), redBright("91"), greenBright("92"), yellowBright("93"), blueBright("94"), magentaBright("95"), cyanBright("96"), whiteBright("97"), BLACK_BRIGHT("100"), RED_BRIGHT("101"), GREEN_BRIGHT("102"), YELLOW_BRIGHT("103"), BLUE_BRIGHT("104"), MAGENTA_BRIGHT("105"), CYAN_BRIGHT("106"), WHITE_BRIGHT("107");

} // namespace payam

#endif
