#ifndef HELP_HPP
#define HELP_HPP

#include "actor.hpp"
#include "util/arg-parser.hpp"

class Help : public Actor<void> {
public:
  void showHelp();
  void action() override;
};

#endif
